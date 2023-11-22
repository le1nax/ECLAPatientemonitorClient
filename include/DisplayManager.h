#pragma once
#include <iostream>

#include "definitions.h"

//PCANModule includes
#include "../PCANModule/DataPoint.h"

#include <thread>

#include <vector>
#include <iostream>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

class DisplayManager {
    public:

        DisplayManager();

        DisplayManager(const DisplayManager&) = delete;
        DisplayManager& operator=(const DisplayManager&) = delete;

        DisplayManager(DisplayManager&&) = delete;
        DisplayManager& operator=(DisplayManager&&) = delete;

        void initWindow();

        void onPressureChanged(const DataPoint& dataPointReceived);

        virtual ~DisplayManager();

    private:

        void DisplayThread();
        std::vector<float> m_BPData = {};
        std::unique_ptr<std::thread> displayWindowThread {nullptr};


};

