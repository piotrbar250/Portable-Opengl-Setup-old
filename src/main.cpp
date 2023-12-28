#include <iostream>
#include <cmath>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"

#include "UI.h"

bool ToggleSwitch(const char *label, bool &isToggled)
{
    ImGui::Text("%s", label);
    ImGui::SameLine();

    ImVec2 p = ImGui::GetCursorScreenPos();
    float height = ImGui::GetFrameHeight();
    float width = height * 2.3f;
    float radius = height * 0.50f;
    float sliderPos = isToggled ? (width - radius) : radius;

    ImGui::InvisibleButton("##toggle", ImVec2(width, height));
    if (ImGui::IsItemActive() && ImGui::IsMouseDragging(ImGuiMouseButton_Left))
    {
        sliderPos = ImGui::GetIO().MousePos.x - p.x - radius;
        sliderPos = (sliderPos < radius) ? radius : (sliderPos > width - radius) ? width - radius
                                                                                 : sliderPos;
    }

    isToggled = sliderPos > width * 0.5f;

    ImU32 col_bg = isToggled ? IM_COL32(30, 144, 255, 255) : IM_COL32(150, 150, 150, 255);
    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
    draw_list->AddCircleFilled(ImVec2(p.x + sliderPos, p.y + radius), radius - 1.0f, IM_COL32(255, 255, 255, 255));

    return isToggled;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    if (!glfwInit())
    {
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(2);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Couldn't load opengl" << std::endl;
        glfwTerminate();
        return -1;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

    bool simulation = true;
    while (!glfwWindowShouldClose(window))
    {
        glfwWaitEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        simulation = ToggleSwitch("Simulation", simulation);

        glClear(GL_COLOR_BUFFER_BIT);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();

    return 0;
}

// // how can you configure a callback mechanism for example. My question is how do you efficiently inform main thread that new client connected from another thread. I want to avoid busy waiting

