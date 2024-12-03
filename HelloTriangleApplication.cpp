#include "HelloTriangleApplication.h"

#include <iostream>
#include <stdexcept>
#include <vector>

void HelloTriangleApplication::run() {
  initVulkan();
  mainLoop();
  cleanup();
}

void HelloTriangleApplication::initVulkan() {
  if (!glfwInit()) {
    throw std::runtime_error("Failed to initialize GLFW");
  }
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

  createInstance();
}

void HelloTriangleApplication::mainLoop() {
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }
}

void HelloTriangleApplication::cleanup() {
  vkDestroyInstance(instance, nullptr);

  glfwDestroyWindow(window);

  glfwTerminate();
}

void HelloTriangleApplication::createInstance() {
  VkApplicationInfo appInfo{};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Hello Triangle";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  uint32_t glfwExtensionCount = 0;
  const char** glfwExtensions;

  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  VkInstanceCreateInfo instanceCreateInfo{};
  instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instanceCreateInfo.pApplicationInfo = &appInfo;
  instanceCreateInfo.enabledExtensionCount = glfwExtensionCount;
  instanceCreateInfo.ppEnabledExtensionNames = glfwExtensions;
  instanceCreateInfo.enabledLayerCount = 0;

  if (vkCreateInstance(&instanceCreateInfo, nullptr, &instance) != VK_SUCCESS) {
    throw std::runtime_error("failed to create instance!");
  }
}
