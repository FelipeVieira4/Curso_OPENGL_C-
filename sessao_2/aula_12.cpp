/*
Trabalhar com vetores usando biblioteca GLM

*/
#include<iostream>
#include<cassert>

#include<glm/glm.hpp>
#include<glm/gtx/string_cast.hpp>

using namespace std;



void constructors(){

    

    glm::vec2 point2D{25.0f,50.0f};
    glm::vec3 point3D{10.0f,0.0f,0.0f};
    glm::vec3 point3DFrom2D{point2D,7.0f};
    glm::vec4 point4D{2.0f,5.0f,0.0f,-10.0f};

    glm::ivec2 pointInteger2D{2,5}; // Vetor de tipo inteiro

    glm::bvec2 pointboolean2D{true,false};

    std::cout<<"POINT 2D: "<< glm::to_string(point2D)<<std::endl;
    std::cout<<"POINT 3D: "<< glm::to_string(point3D)<<std::endl;
    std::cout<<"POINT 4D: "<< glm::to_string(point4D)<<std::endl;

    std::cout<<"POINT FROM 2D: "<< glm::to_string(point3DFrom2D)<<std::endl;

    std::cout<<"POINT INT : "<< glm::to_string(pointInteger2D)<<std::endl;

    std::cout<<"POINT BOOL : "<< glm::to_string(pointboolean2D)<<std::endl;
}

void components(){


    glm::vec3 p {1.0f,2.0f,3.0f};

    cout << "X:" << p.x << " Y:" << p.y << " Z:" << p.z << endl;

    cout << "R:" << p.r << " G:" << p.g << " B:" << p.b << endl;

    cout << "0:" << p[0] << " 1:" << p[1] << " 2:" << p[2] << endl;
}

void Swizzle(){

    glm::vec3 point{1,2,3};

    glm::vec3 T = point;

    cout<<glm::to_string(T)<<endl;
}

glm::vec3 Operadores(){

    glm::vec3 point1{6,12,4};

    glm::vec3 point2{47,2,32};

    return (glm::vec3){point1+point2};
}

int main(void){

    cout << endl;

    constructors();

    cout <<"COMPONENTES"<< endl;

    components();

    cout <<"Swizzle"<< endl;

    Swizzle();


    glm::vec3 p = Operadores();
    cout<<glm::to_string(p)<<endl;

    return 0;
}