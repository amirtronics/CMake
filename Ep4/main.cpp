#include <iostream>
#include <GLFW/glfw3.h>
#include <OLASConfig.h>
#ifdef USE_ADDER
    #include <adder_m.h>
#endif

int main(int argc, char* argv[])
{
    std::cout << "Hey, Zeus!\n";

    std::cout << add(4, 3) << "\n";

    std::cout << 4 + 3 << "\n";


    std::cout << argv[0] << " Version " << OLAS_VERSION_MAJOR << "." << OLAS_VERSION_MINOR << "\n";

    GLFWwindow *window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    while( !glfwWindowShouldClose(window) )
    {
        // Draw gears
        // draw();

        // Update animation
        // animate();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}