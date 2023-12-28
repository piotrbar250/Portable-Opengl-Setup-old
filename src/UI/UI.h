#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"

#include <stdio.h>

inline bool ToggleSwitch(const char *label, bool &isToggled)
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
