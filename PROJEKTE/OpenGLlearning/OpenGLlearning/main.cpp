//
//  main.cpp
//  OpenGLlearning
//
//  Created by Mark on 2020/4/10.
//  Copyright © 2020 Mark. All rights reserved.
//
#define GL_SILENCE_DEPRECATION
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main(int argc, const char * argv[]) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow* window;
    
    if (!glfwInit())
        return -1;
    
    window = glfwCreateWindow(1440, 900, "TestCase1", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window); //必须要把cointext先initialize
    
    if(glewInit() != GLEW_OK) {
        cout << "Something is wrong with the app, please try again." << endl;
        return -1;
    }
    
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.3f, -0.4f);
        glVertex2f(0.0f, 0.4f);
        glVertex2f(0.3f, -0.4f);
        glEnd();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
