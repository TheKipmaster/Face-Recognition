#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include "Usuario.hpp"
#include "Reserva.hpp"
#include "LINF.hpp"

using namespace cv;

std::string face_cascade_name = "/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;

Mat detectAndDisplay(Mat frame, std::string nome, std::string *caminho, unsigned int i) {
    std::vector<Rect> faces;
    Mat frame_gray;
    Mat crop;
    Mat res;
    Mat gray;
    std::string text;

    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);

    // Detect faces
    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

    // Set Region of Interest
    cv::Rect roi_b;
    cv::Rect roi_c;

    size_t ic = 0; // ic is index of current element
    int ac = 0; // ac is area of current element

    size_t ib = 0; // ib is index of biggest element
    int ab = 0; // ab is area of biggest element
    for (ic = 0; ic < faces.size(); ic++) // Iterate through all current elements (detected faces)
    {   
        // string caminho;
        roi_c.x = faces[ic].x;
        roi_c.y = faces[ic].y;
        roi_c.width = (faces[ic].width);
        roi_c.height = (faces[ic].height);

        ac = roi_c.width * roi_c.height; // Get the area of current element (detected face)

        roi_b.x = faces[ib].x;
        roi_b.y = faces[ib].y;
        roi_b.width = (faces[ib].width);
        roi_b.height = (faces[ib].height);

        ab = roi_b.width * roi_b.height; // Get the area of biggest element, at beginning it is same as "current" element

        if (ac > ab)
        {
            ib = ic;
            roi_b.x = faces[ib].x;
            roi_b.y = faces[ib].y;
            roi_b.width = (faces[ib].width);
            roi_b.height = (faces[ib].height);
        }

        crop = frame(roi_b);
        resize(crop, res, Size(128, 128), 0, 0, INTER_LINEAR); // This will be needed later while saving images
        cvtColor(crop, gray, CV_BGR2GRAY); // Convert cropped image to Grayscale

        // Form a filename
        (*caminho) = "img/"+ nome + "/"+ nome + std::to_string(i) +".png";
        i++;   

        Point pt1(faces[ic].x, faces[ic].y); // Display detected faces on main window - live stream from camera
        Point pt2((faces[ic].x + faces[ic].height), (faces[ic].y + faces[ic].width));
        rectangle(frame, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
        imshow("original", frame);
    }
    return gray;
}

void openCamera(std::string nome) {

    char c;
    unsigned int i;
    std::string caminho;
    Mat gray;
    // Load the cascade
    if (!face_cascade.load(face_cascade_name)){
        printf("--(!)Error loading\n");
        exit(-1);
    }

    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        exit(-1);
    std::string folderCreateCommand = "mkdir img/" + nome;
    system(folderCreateCommand.c_str());
    for(i=1;i<=5;i++) {
        while(true) {
            Mat frame;
            cap >> frame;
            gray = detectAndDisplay(frame, nome, &caminho, i);
            c = waitKey(25);
            if(c != -1) {
                destroyWindow("original");
                imwrite(caminho, gray); 
                break;
            }
        }
    }
}

void loadUsers(LINF *linf) {
  Usuario usuario;
  std::ifstream ifs("usuarios.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ifs, obj); // reader can also read strings
  const Json::Value& usuarios = obj["usuarios"]; // array of characters
  for (unsigned int i = 0; i < usuarios.size(); i++){
    usuario.setId(usuarios[i]["id"].asString());
    usuario.setNome(usuarios[i]["nome"].asString());
    usuario.setNomeDoMeio(usuarios[i]["nome_do_meio"].asString());
    usuario.setSobrenome(usuarios[i]["sobrenome"].asString());
    usuario.setTipoDeUsuario(usuarios[i]["tipo"].asString());
    linf->salvarUsuario(usuario);
  }
}

void loadReservas(LINF *linf) {

  Reserva reserva;
  Usuario usuario;
  std::ifstream ifs("reservas.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ifs, obj); // reader can also read strings
  const Json::Value& reservas = obj["reservas"];
  for (unsigned int i = 0; i < reservas.size(); i++){
    reserva.setIdCriador(reservas[i]["id_criador"].asString());
    reserva.setProposito(reservas[i]["proposito"].asString());
    reserva.setNumeroSalas(reservas[i]["numero_salas"].asString());
    reserva.setHorarioInicio(reservas[i]["horario_inicio"].asString());
    reserva.setHorarioFim(reservas[i]["horario_fim"].asString());
    reserva.setRecorrente(reservas[i]["recorrente"].asBool());
    reserva.setDiasRecorrentes(reservas[i]["dias_recorrentes"].asString());
    reserva.setDataInicio(reservas[i]["data_inicio"].asString());
    reserva.setDataFim(reservas[i]["data_fim"].asString());    
    for (unsigned int j = 0; j < reservas[i]["participantes"].size(); j++){
      usuario.setId(reservas[i]["participantes"][j]["id"].asString());
      usuario.setNome(reservas[i]["participantes"][j]["nome"].asString());
      usuario.setNomeDoMeio(reservas[i]["participantes"][j]["nome_do_meio"].asString());
      usuario.setSobrenome(reservas[i]["participantes"][j]["sobrenome"].asString());
      usuario.setTipoDeUsuario(reservas[i]["participantes"][j]["tipo"].asString());
      reserva.addParticipante(usuario);
    }
    linf->salvarReserva(reserva);
  }

}

void saveRecords(LINF *linf) {
  int i;
  Json::Value usuarios;
  Json::Value usuario;
  Json::Value vec(Json::arrayValue);
  for(i=0;i < linf->usuariosCadastrados();i++){
    usuario["id"] = linf->getUsuario(i).getId();
    usuario["nome"] = linf->getUsuario(i).getNome();
    usuario["nome_do_meio"] = linf->getUsuario(i).getNomeDoMeio();
    usuario["sobrenome"] = linf->getUsuario(i).getSobrenome();
    usuario["tipo"] = linf->getUsuario(i).getTipoDeUsuario();
    vec.append(Json::Value(usuario));
    usuarios["usuarios"]=vec;
  }
  std::fstream fs;
  fs.open ("usuarios.json", std::fstream::in | std::fstream::out);

  fs << usuarios;

  fs.close();
}

void saveReservas(LINF *linf) {
  unsigned int i, j;
  Json::Value reservas;
  Json::Value reserva;
  Json::Value usuario;
  Json::Value vec(Json::arrayValue);
  Json::Value vec1(Json::arrayValue);

  for(i=0;i < linf->getReservas().size();i++){

    reserva["id_criador"] = linf->indexReserva(i).getIdCriador();
    reserva["proposito"] = linf->indexReserva(i).getProposito();
    reserva["numero_salas"] = linf->indexReserva(i).getNumeroSalas();
    reserva["horario_inicio"] = linf->indexReserva(i).getHorarioInicio();
    reserva["horario_fim"] = linf->indexReserva(i).getHorarioFim();
    reserva["recorrente"] = linf->indexReserva(i).getRecorrente();
    reserva["dias_recorrentes"] = linf->indexReserva(i).getDiasRecorrentes();
    reserva["data_inicio"] = linf->indexReserva(i).getDataInicio();
    reserva["data_fim"] = linf->indexReserva(i).getDataFim();

    for(j=0; j < linf->indexReserva(i).getParticipantes().size(); j++){
      usuario["id"] =  linf->indexReserva(i).getParticipante(j).getId();
      usuario["nome"] = linf->indexReserva(i).getParticipante(j).getNome();
      usuario["nome_do_meio"] = linf->indexReserva(i).getParticipante(j).getNomeDoMeio();
      usuario["sobrenome"] = linf->indexReserva(i).getParticipante(j).getSobrenome();
      usuario["tipo"] = linf->indexReserva(i).getParticipante(j).getTipoDeUsuario();
      vec1.append(Json::Value(usuario));
      reserva["participantes"] = vec1;
    }

    vec.append(Json::Value(reserva));
    reservas["reservas"]= vec;
  }
  
  std::fstream fs;
  fs.open ("reservas.json", std::fstream::in | std::fstream::out);

  fs << reservas;

  fs.close();
}

void addParticipantes(Reserva *reserva, LINF linf) {
  std::string input;
  int posicao_usuario;

  std::cout << "(pressione <ENTER> após cada entrada | digite 'sair' para terminar)" << std::endl;
  do {
    std::cout << "Informe o número de identificação dos participantes da reserva: ";
    std::cin >> input;

    if(input != "sair" && input != "Sair") {
      posicao_usuario = linf.getUsuario(input);
      reserva->addParticipante(linf.getUsuarios().at(posicao_usuario));
    }
  }while(input != "sair" && input != "Sair");
}

int drawSubMenu (int *n) {

  system("clear");
  std::cout << "\tOpa, tudo bom? Bem vindo ao LINF" << std::endl << std::endl;
  std::cout << "1 - Novo Cadastro" << std::endl;
  std::cout << "2 - Nova Reserva" << std::endl;
  std::cout << "3 - Check DB" << std::endl;
  std::cout << "\t3.1 - Index de Usuários" << std::endl;
  std::cout << "\t3.2 - Busca de Usuários" << std::endl;
  std::cout << "\t3.3 - Editar Usuários" << std::endl;
  std::cout << "\t3.4 - Index de Reservas" << std::endl;
  std::cout << "\t3.5 - Voltar" << std::endl << "\t";
	do {
		std::cin >> *n;
		if ( (*n > 5) || (*n < 1) )
			std::cout << "\tEntrada inválida" << std::endl << "\t";
	} while ( (*n > 5) || (*n < 1) );

	return *n;
}

int drawMenu (int *n) {

  system("clear");
  std::cout << "\tOpa, tudo bom? Bem vindo ao LINF" << std::endl << std::endl;
  std::cout << "1 - Novo Cadastro" << std::endl;
  std::cout << "2 - Nova Reserva" << std::endl;
  std::cout << "3 - Check DB" << std::endl;
  std::cout << "4 - Solicitar Permissão" << std::endl;
  std::cout << "5 - Sair" << std::endl;
	do {
		std::cin >> *n;
		if ( (*n > 5) || (*n < 1) )
			std::cout << "Entrada inválida" << std::endl;
	} while ( (*n > 5) || (*n < 1) );

	return *n;
}

int main() {
  int n;
  LINF linf;
  loadUsers(&linf);
  loadReservas(&linf);

  drawMenu(&n);
  while(n != 5) {
    saveRecords(&linf);
    saveReservas(&linf);
    if(n == 1) {
      Usuario usuario;
      usuario.cadastrar();
      openCamera(usuario.getNome());
      linf.salvarUsuario(usuario);
      drawMenu(&n);
    }
    else if(n == 2) {
      Reserva reserva;
      reserva.cadastrar();
      addParticipantes(&reserva, linf);
      linf.salvarReserva(reserva);
      drawMenu(&n);
    }
    else if(n == 3) {
      drawSubMenu(&n);
      while(n != 5) {
        if(n == 1) {
          linf.indexUsuario();
          drawSubMenu(&n);
        }
        else if(n == 2) {
          linf.buscaUsuario();
          drawSubMenu(&n);
        }
        else if(n == 3) {
          linf.editaUsuario();
          drawSubMenu(&n);
        }
        else if(n == 4) {
          linf.indexReserva();
          drawSubMenu(&n);
        }
      }
      drawMenu(&n);
    }
    else if(n == 4) {
      // linf.manejarEntrada();
      drawMenu(&n);
    }
  }

  return 0;
}
