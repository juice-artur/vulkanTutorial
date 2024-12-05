#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <optional>
#include <iostream>
#include <stdexcept>
#include <vector>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;
struct QueueFamilyIndices {
  std::optional<uint32_t> graphicsFamily;

  bool isComplete() { return graphicsFamily.has_value(); }
};

class HelloTriangleApplication {
 public:
  void run();

 private:
  GLFWwindow* window;
  VkInstance instance;
  VkDebugUtilsMessengerEXT debugMessenger;
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VkDevice device;
  VkQueue graphicsQueue;
  const std::vector<const char*> validationLayers = {
      "VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG
  const bool enableValidationLayers = false;
#else
  const bool enableValidationLayers = true;
#endif
  void initVulkan();
  void mainLoop();
  void cleanup();

  bool checkValidationLayerSupport();
  std::vector<const char*> getRequiredExtensions();

  void createInstance();

  static VKAPI_ATTR VkBool32 VKAPI_CALL
  debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                VkDebugUtilsMessageTypeFlagsEXT messageType,
                const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                void* pUserData) {
    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

    return VK_FALSE;
  }

  void populateDebugMessengerCreateInfo(
      VkDebugUtilsMessengerCreateInfoEXT& createInfo);

  void setupDebugMessenger();

  VkResult CreateDebugUtilsMessengerEXT(
      VkInstance instance,
      const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
      const VkAllocationCallbacks* pAllocator,
      VkDebugUtilsMessengerEXT* pDebugMessenger);

  void DestroyDebugUtilsMessengerEXT(VkInstance instance,
                                     VkDebugUtilsMessengerEXT debugMessenger,
                                     const VkAllocationCallbacks* pAllocator);

  bool isDeviceSuitable(VkPhysicalDevice device);
  void pickPhysicalDevice();
  void createLogicalDevice();

  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
};