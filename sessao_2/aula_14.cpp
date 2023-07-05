#include<iostream>
#include<cassert>
#include<array>

#include<GL/glew.h>
#include<GLFW/glfw3.h> //Para criar o contexto do OPENGL

#include<glm/glm.hpp>

//Tamanho da janela
const int widht = 800;
const int height = 600;

int main(void){

    //assert(glfwInit()); //Inicializar o GLFW
    if(!glfwInit()){
        std::cout<<"ERRO INCIALIZAR GLFW"<<std::endl;
        return 1;//Sair com erro
    }


    GLFWwindow* window = glfwCreateWindow(widht,height,"BlueMarble",nullptr,nullptr);//Criar a janela
    //assert(window);//Checar se o ponteiro da janela não é nulo
    if(!window){
        std::cout<<"ERRO AO CRIAR O CONTEXTO GLFW(window null)"<<std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

    //Inicializar o GLEW
    if(glewInit()!= GLEW_OK){ 
        std::cout<<"ERRO LOAD GLEW"<<std::endl;
        return -1;
    }



    //Definir array do tipo "vec3" e com número de elementos 3
    std::array<glm::vec3,3> triangulo ={
        glm::vec3 {-1.0f,-1.0f,0.0f},
        glm::vec3 {1.0f,-1.0f,0.0f},
        glm::vec3 {0.0f,1.0f,0.0f}
    };

    //formato primitivo int unsigned
    GLuint VertexBuffer; // ponteiro
    std::cout<<VertexBuffer<<std::endl;

    //Gerar um buffer de vertices
    glGenBuffers(1,&VertexBuffer);


    //Habilitar o "VertexBuffer" como "GL_ARRAY_BUFFER" para copiar os valores do vertex "triangulo"
    glBindBuffer(GL_ARRAY_BUFFER,VertexBuffer);

    //Copiar os dados do "triangulo" para VertexBuffer
    glBufferData(GL_ARRAY_BUFFER,sizeof(triangulo),triangulo.data(),GL_STATIC_DRAW);



    //Definir cor de fundo
    glClearColor(0.0f,0.5f,0.0f,0.0f);

    //Loop eventos
    while(!glfwWindowShouldClose(window)){

        //Limpar o buffer
        glClear(GL_COLOR_BUFFER_BIT);


        glEnableVertexAttribArray(0);//Habilitar o uso de vertex a partir da posição 0 ou seja ID

        //Colocar o VertexBuffer como o buffer ativo no momento
        glBindBuffer(GL_ARRAY_BUFFER,VertexBuffer);

        //Informa ao OpenGL onde, dentro do VertexBuffer, os vértices estão
        glVertexAttribPointer(0,triangulo.size(),GL_FLOAT,GL_FALSE,0,nullptr);

        //Desenhar um triangulo com os dados do VertexBuffer
        glDrawArrays(GL_TRIANGLES,0,triangulo.size());

        glBindBuffer(GL_ARRAY_BUFFER,0);//Para zerar o buffer



        glDisableVertexAttribArray(0);//Disabilitar "generic vertex attribute arrays"

        glfwPollEvents();//Processa todos os eventos da fila do GLFW (mouse,gamepad,teclado)

        glfwSwapBuffers(window);//envia o conteúdo do frame buffer para ser desenhado na tela
    }

    glDeleteBuffers(1,&VertexBuffer);//Limpar o VertexBuffer da mémoria da GPU

    glfwTerminate();//Finalizar biblioteca GLFW

    return 0;
}