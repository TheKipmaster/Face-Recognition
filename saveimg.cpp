#include "opencv2/opencv.hpp"
#include <string>
#include <stdlib.h>


using namespace cv;
using namespace std;

int main()
{
	int i;
	string caminho;
	string nome = "Danilo";
	string folderCreateCommand = "mkdir img/" + nome;
	system(folderCreateCommand.c_str()); //Passando um array de char para system
	VideoCapture cap(0); // open the default camera
	if(!cap.isOpened())  // check if we succeeded
		return -1;
	for(i=1;i<=5;i++){
		while(true)
		{
			Mat frame;
			cap >> frame;
			caminho = "img/"+ nome + "/"+ nome + to_string(i) +".png";
			imshow("Capturar foto", frame);
			imwrite(caminho, frame);
			if(waitKey(30) >= 0){
				destroyWindow("Capturar foto");
				break;
			} 
		}
	}
	return 0;
}