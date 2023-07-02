#include<iostream>
#include<cassert>

#include<GLFW/glfw3.h> //Para criar o contexto do OPENGL

//Tamanho da janela
const int widht = 600;
const int height = 480;

int main(void){

    assert(glfwInit()); //Inicializar o GLFW

    GLFWwindow* window = glfwCreateWindow(widht,height,"BlueMarble",nullptr,nullptr);//Criar a janela

    assert(window);//Checar se o ponteiro da janela não é nulo


    //Loop eventos

    while(!glfwWindowShouldClose(window)){

        glfwPollEvents();//Processa todos os eventos da fila do GLFW (mouse,gamepad,teclado)


        glfwSwapBuffers(window);//envia o conteúdo do frame buffer para ser desenhado na tela

    }

    glfwTerminate();//Finalizar biblioteca GLFW

    return 0;
}