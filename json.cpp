#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>


int main()
{
    Json::Value usuarios;
    Json::Value usuario;   
    Json::Value vec(Json::arrayValue);

    usuario["id"] = "160026270";
    usuario["nome"] = "Danilo";
    usuario["sobrenome"] = "Cabrinha";
    usuario["nome_do_meio"] = "de Lima";
    usuario["tipo_de_usuario"] = "aluno";
    vec.append(Json::Value(usuario));
    usuarios["usuarios"]=vec;

    

    
}