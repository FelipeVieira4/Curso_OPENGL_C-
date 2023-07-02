#include<iostream>
#include<cassert>

//#include<GL/gl.h> opengl versão 1 desatualizado

#include<GL/glew.h>
#include<GLFW/glfw3.h> //Para criar o contexto do OPENGL

//Tamanho da janela
const int widht = 600;
const int height = 480;

int main(void){

    assert(glfwInit()); //Inicializar o GLFW
                                                                    
    GLFWwindow* window = glfwCreateWindow(widht,height,"BlueMarble",nullptr,nullptr);//Criar a janela
    assert(window);//Checar se o ponteiro da janela não é nulo

    glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

    //Inicializar o GLEW
    if(glewInit()!= GLEW_OK){ 
        std::cout<<"ERRO GLEW"<<std::endl;
        return -1;
    }

    std::cout<<"OpenGL Vendor : "<< glGetString(GL_VENDOR)<<std::endl;
    std::cout<<"OpenGL RENDERER : "<< glGetString(GL_RENDERER)<<std::endl;
    std::cout<<"OpenGL VERSION : "<< glGetString(GL_VERSION)<<std::endl;

    //Definir cor de fundo
    glClearColor(1.0f,0.0f,0.0f,0.0f);


    //Loop eventos
    while(!glfwWindowShouldClose(window)){

        //Limpar o buffer
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();//Processa todos os eventos da fila do GLFW (mouse,gamepad,teclado)


        glfwSwapBuffers(window);//envia o conteúdo do frame buffer para ser desenhado na tela
    }

    glfwTerminate();//Finalizar biblioteca GLFW

    return 0;
}