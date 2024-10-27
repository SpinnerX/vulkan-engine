/* #include "Event/Input.hpp" */
/* #include "Event/KeyCodes.hpp" */
/* #include <cstdio> */
/* #include <cstdlib> */
/* #include <imgui.h> */
/* #include <vulkan-engine/Application.hpp> */
/* #include <vulkan-engine/EntryPoint.hpp> */
/* #include <vulkan-engine/Image/Image.hpp> */
/* /1* #include <imgui/imgui.h> *1/ */
/* #include <imgui/backends/imgui_impl_glfw.h> */
/* #include <imgui/backends/imgui_impl_vulkan.h> */
/* #include <GLFW/glfw3.h> */
/* class ExampleLayer : public MiniGameEngine::Layer */
/* { */
/* public: */
/*     ExampleLayer(){ */
        
/*     } */

/*     virtual void onUpdate(float ts) override{ */
/*         if(MiniGameEngine::Input::isKeyPressed(MiniGameEngine::Key::Escape)){ */
/*             exit(0); */
/*         } */
/*     } */

/* 	virtual void onUIRender() override{ */
/*         printf("onUIRender() called!\n"); */
/*         ImGui::Begin("Settings"); */
/*         /1* ImGui::Text("Last render: %.3fms", lastRenderTime); *1/ */
/*         ImGui::Text("Render Text"); */
/*         /1* if (ImGui::Button("Render")){ *1/ */
/*         /1*     Render(); *1/ */
/*         /1* } *1/ */
/*         ImGui::End(); */

/*         ImGui::Begin("Scene"); */
/*         /1* for (size_t i = 0; i < scene.Spheres.size(); i++){ *1/ */
/*         /1*     ImGui::PushID(i); *1/ */

/*             /1* Sphere& sphere = scene.Spheres[i]; *1/ */
/*             /1* ImGui::DragFloat3("Position", glm::value_ptr(sphere.Position), 0.1f); *1/ */
/*             /1* ImGui::DragFloat("Radius", &sphere.Radius, 0.1f); *1/ */
/*             /1* ImGui::ColorEdit3("Albedo", glm::value_ptr(sphere.Albedo)); *1/ */

/*             /1* ImGui::Separator(); *1/ */

/*             /1* ImGui::PopID(); *1/ */
/*         /1* } *1/ */
/*         ImGui::End(); */

/*         ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f)); */
/*         ImGui::Begin("Viewport"); */

/*         /1* viewportWidth = ImGui::GetContentRegionAvail().x; *1/ */
/*         /1* viewportHeight = ImGui::GetContentRegionAvail().y; *1/ */

/*         /1* auto image = renderer.getFinalImage(); *1/ */
/*         /1* if (image) *1/ */
/*         /1*     ImGui::Image(image->getDescriptorSet(), { (float)image->getWidth(), (float)image->getHeight() }, *1/ */
/*                     /1* ImVec2(0, 1), ImVec2(1, 0)); *1/ */

/*         ImGui::End(); */
/*         ImGui::PopStyleVar(); */
/* 	} */
/* }; */

/* MiniGameEngine::Application* MiniGameEngine::CreateApplication(int argc, char** argv){ */
/* 	MiniGameEngine::ApplicationSpecification spec; */
/* 	spec.name = "MiniGameEngine Example"; */

/* 	MiniGameEngine::Application* app = new MiniGameEngine::Application(spec); */
/* 	app->pushLayer<ExampleLayer>(); */
/* 	app->setMenubarCallback([app](){ */
/* 		if (ImGui::BeginMenu("File")){ */
/* 			if (ImGui::MenuItem("Exit")){ */
/* 				app->close(); */
/* 			} */
/* 			ImGui::EndMenu(); */
/* 		} */
/* 	}); */
/* 	return app; */
/* } */

/* /1* // [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers. *1/ */
/* /1* // To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma. *1/ */
/* /1* // Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio. *1/ */
/* /1* #if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS) *1/ */
/* /1* #pragma comment(lib, "legacy_stdio_definitions") *1/ */
/* /1* #endif *1/ */

/* /1* //#define APP_USE_UNLIMITED_FRAME_RATE *1/ */
/* /1* #ifdef _DEBUG *1/ */
/* /1* #define APP_USE_VULKAN_DEBUG_REPORT *1/ */
/* /1* #endif *1/ */

/* /1* // Data *1/ */
/* /1* static VkAllocationCallbacks*   g_Allocator = nullptr; *1/ */
/* /1* static VkInstance               g_Instance = VK_NULL_HANDLE; *1/ */
/* /1* static VkPhysicalDevice         g_PhysicalDevice = VK_NULL_HANDLE; *1/ */
/* /1* static VkDevice                 g_Device = VK_NULL_HANDLE; *1/ */
/* /1* static uint32_t                 g_QueueFamily = (uint32_t)-1; *1/ */
/* /1* static VkQueue                  g_Queue = VK_NULL_HANDLE; *1/ */
/* /1* static VkDebugReportCallbackEXT g_DebugReport = VK_NULL_HANDLE; *1/ */
/* /1* static VkPipelineCache          g_PipelineCache = VK_NULL_HANDLE; *1/ */
/* /1* static VkDescriptorPool         g_DescriptorPool = VK_NULL_HANDLE; *1/ */

/* /1* static ImGui_ImplVulkanH_Window g_MainWindowData; *1/ */
/* /1* static int                      g_MinImageCount = 2; *1/ */
/* /1* static bool                     g_SwapChainRebuild = false; *1/ */

/* /1* static void glfw_error_callback(int error, const char* description) *1/ */
/* /1* { *1/ */
/* /1*     fprintf(stderr, "GLFW Error %d: %s\n", error, description); *1/ */
/* /1* } *1/ */
/* /1* static void check_vk_result(VkResult err) *1/ */
/* /1* { *1/ */
/* /1*     if (err == 0) *1/ */
/* /1*         return; *1/ */
/* /1*     fprintf(stderr, "[vulkan] Error: VkResult = %d\n", err); *1/ */
/* /1*     if (err < 0) *1/ */
/* /1*         abort(); *1/ */
/* /1* } *1/ */

/* /1* #ifdef APP_USE_VULKAN_DEBUG_REPORT *1/ */
/* /1* static VKAPI_ATTR VkBool32 VKAPI_CALL debug_report(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage, void* pUserData) *1/ */
/* /1* { *1/ */
/* /1*     (void)flags; (void)object; (void)location; (void)messageCode; (void)pUserData; (void)pLayerPrefix; // Unused arguments *1/ */
/* /1*     fprintf(stderr, "[vulkan] Debug report from ObjectType: %i\nMessage: %s\n\n", objectType, pMessage); *1/ */
/* /1*     return VK_FALSE; *1/ */
/* /1* } *1/ */
/* /1* #endif // APP_USE_VULKAN_DEBUG_REPORT *1/ */

/* /1* static bool IsExtensionAvailable(const ImVector<VkExtensionProperties>& properties, const char* extension) *1/ */
/* /1* { *1/ */
/* /1*     for (const VkExtensionProperties& p : properties) *1/ */
/* /1*         if (strcmp(p.extensionName, extension) == 0) *1/ */
/* /1*             return true; *1/ */
/* /1*     return false; *1/ */
/* /1* } *1/ */

/* /1* static VkPhysicalDevice SetupVulkan_SelectPhysicalDevice() *1/ */
/* /1* { *1/ */
/* /1*     uint32_t gpu_count; *1/ */
/* /1*     VkResult err = vkEnumeratePhysicalDevices(g_Instance, &gpu_count, nullptr); *1/ */
/* /1*     check_vk_result(err); *1/ */
/* /1*     IM_ASSERT(gpu_count > 0); *1/ */

/* /1*     ImVector<VkPhysicalDevice> gpus; *1/ */
/* /1*     gpus.resize(gpu_count); *1/ */
/* /1*     err = vkEnumeratePhysicalDevices(g_Instance, &gpu_count, gpus.Data); *1/ */
/* /1*     check_vk_result(err); *1/ */

/* /1*     // If a number >1 of GPUs got reported, find discrete GPU if present, or use first one available. This covers *1/ */
/* /1*     // most common cases (multi-gpu/integrated+dedicated graphics). Handling more complicated setups (multiple *1/ */
/* /1*     // dedicated GPUs) is out of scope of this sample. *1/ */
/* /1*     for (VkPhysicalDevice& device : gpus) *1/ */
/* /1*     { *1/ */
/* /1*         VkPhysicalDeviceProperties properties; *1/ */
/* /1*         vkGetPhysicalDeviceProperties(device, &properties); *1/ */
/* /1*         if (properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) *1/ */
/* /1*             return device; *1/ */
/* /1*     } *1/ */

/* /1*     // Use first GPU (Integrated) is a Discrete one is not available. *1/ */
/* /1*     if (gpu_count > 0) *1/ */
/* /1*         return gpus[0]; *1/ */
/* /1*     return VK_NULL_HANDLE; *1/ */
/* /1* } *1/ */

/* /1* static void SetupVulkan(ImVector<const char*> instance_extensions) *1/ */
/* /1* { *1/ */
/* /1*     VkResult err; *1/ */
/* /1* #ifdef IMGUI_IMPL_VULKAN_USE_VOLK *1/ */
/* /1*     volkInitialize(); *1/ */
/* /1* #endif *1/ */

/* /1*     // Create Vulkan Instance *1/ */
/* /1*     { *1/ */
/* /1*         VkInstanceCreateInfo create_info = {}; *1/ */
/* /1*         create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO; *1/ */

/* /1*         // Enumerate available extensions *1/ */
/* /1*         uint32_t properties_count; *1/ */
/* /1*         ImVector<VkExtensionProperties> properties; *1/ */
/* /1*         vkEnumerateInstanceExtensionProperties(nullptr, &properties_count, nullptr); *1/ */
/* /1*         properties.resize(properties_count); *1/ */
/* /1*         err = vkEnumerateInstanceExtensionProperties(nullptr, &properties_count, properties.Data); *1/ */
/* /1*         check_vk_result(err); *1/ */

/* /1*         // Enable required extensions *1/ */
/* /1*         if (IsExtensionAvailable(properties, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME)) *1/ */
/* /1*             instance_extensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME); *1/ */
/* /1* #ifdef VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME *1/ */
/* /1*         if (IsExtensionAvailable(properties, VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME)) *1/ */
/* /1*         { *1/ */
/* /1*             instance_extensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME); *1/ */
/* /1*             create_info.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR; *1/ */
/* /1*         } *1/ */
/* /1* #endif *1/ */

/* /1*         // Enabling validation layers *1/ */
/* /1* #ifdef APP_USE_VULKAN_DEBUG_REPORT *1/ */
/* /1*         const char* layers[] = { "VK_LAYER_KHRONOS_validation" }; *1/ */
/* /1*         create_info.enabledLayerCount = 1; *1/ */
/* /1*         create_info.ppEnabledLayerNames = layers; *1/ */
/* /1*         instance_extensions.push_back("VK_EXT_debug_report"); *1/ */
/* /1* #endif *1/ */

/* /1*         // Create Vulkan Instance *1/ */
/* /1*         create_info.enabledExtensionCount = (uint32_t)instance_extensions.Size; *1/ */
/* /1*         create_info.ppEnabledExtensionNames = instance_extensions.Data; *1/ */
/* /1*         err = vkCreateInstance(&create_info, g_Allocator, &g_Instance); *1/ */
/* /1*         check_vk_result(err); *1/ */
/* /1* #ifdef IMGUI_IMPL_VULKAN_USE_VOLK *1/ */
/* /1*         volkLoadInstance(g_Instance); *1/ */
/* /1* #endif *1/ */

/* /1*         // Setup the debug report callback *1/ */
/* /1* #ifdef APP_USE_VULKAN_DEBUG_REPORT *1/ */
/* /1*         auto f_vkCreateDebugReportCallbackEXT = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(g_Instance, "vkCreateDebugReportCallbackEXT"); *1/ */
/* /1*         IM_ASSERT(f_vkCreateDebugReportCallbackEXT != nullptr); *1/ */
/* /1*         VkDebugReportCallbackCreateInfoEXT debug_report_ci = {}; *1/ */
/* /1*         debug_report_ci.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT; *1/ */
/* /1*         debug_report_ci.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT | VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT; *1/ */
/* /1*         debug_report_ci.pfnCallback = debug_report; *1/ */
/* /1*         debug_report_ci.pUserData = nullptr; *1/ */
/* /1*         err = f_vkCreateDebugReportCallbackEXT(g_Instance, &debug_report_ci, g_Allocator, &g_DebugReport); *1/ */
/* /1*         check_vk_result(err); *1/ */
/* /1* #endif *1/ */
/* /1*     } *1/ */

/* /1*     // Select Physical Device (GPU) *1/ */
/* /1*     g_PhysicalDevice = SetupVulkan_SelectPhysicalDevice(); *1/ */

/* /1*     // Select graphics queue family *1/ */
/* /1*     { *1/ */
/* /1*         uint32_t count; *1/ */
/* /1*         vkGetPhysicalDeviceQueueFamilyProperties(g_PhysicalDevice, &count, nullptr); *1/ */
/* /1*         VkQueueFamilyProperties* queues = (VkQueueFamilyProperties*)malloc(sizeof(VkQueueFamilyProperties) * count); *1/ */
/* /1*         vkGetPhysicalDeviceQueueFamilyProperties(g_PhysicalDevice, &count, queues); *1/ */
/* /1*         for (uint32_t i = 0; i < count; i++) *1/ */
/* /1*             if (queues[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) *1/ */
/* /1*             { *1/ */
/* /1*                 g_QueueFamily = i; *1/ */
/* /1*                 break; *1/ */
/* /1*             } *1/ */
/* /1*         free(queues); *1/ */
/* /1*         IM_ASSERT(g_QueueFamily != (uint32_t)-1); *1/ */
/* /1*     } *1/ */

/* /1*     // Create Logical Device (with 1 queue) *1/ */
/* /1*     { *1/ */
/* /1*         ImVector<const char*> device_extensions; *1/ */
/* /1*         device_extensions.push_back("VK_KHR_swapchain"); *1/ */

/* /1*         // Enumerate physical device extension *1/ */
/* /1*         uint32_t properties_count; *1/ */
/* /1*         ImVector<VkExtensionProperties> properties; *1/ */
/* /1*         vkEnumerateDeviceExtensionProperties(g_PhysicalDevice, nullptr, &properties_count, nullptr); *1/ */
/* /1*         properties.resize(properties_count); *1/ */
/* /1*         vkEnumerateDeviceExtensionProperties(g_PhysicalDevice, nullptr, &properties_count, properties.Data); *1/ */
/* /1* #ifdef VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME *1/ */
/* /1*         if (IsExtensionAvailable(properties, VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME)) *1/ */
/* /1*             device_extensions.push_back(VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME); *1/ */
/* /1* #endif *1/ */

/* /1*         const float queue_priority[] = { 1.0f }; *1/ */
/* /1*         VkDeviceQueueCreateInfo queue_info[1] = {}; *1/ */
/* /1*         queue_info[0].sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO; *1/ */
/* /1*         queue_info[0].queueFamilyIndex = g_QueueFamily; *1/ */
/* /1*         queue_info[0].queueCount = 1; *1/ */
/* /1*         queue_info[0].pQueuePriorities = queue_priority; *1/ */
/* /1*         VkDeviceCreateInfo create_info = {}; *1/ */
/* /1*         create_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO; *1/ */
/* /1*         create_info.queueCreateInfoCount = sizeof(queue_info) / sizeof(queue_info[0]); *1/ */
/* /1*         create_info.pQueueCreateInfos = queue_info; *1/ */
/* /1*         create_info.enabledExtensionCount = (uint32_t)device_extensions.Size; *1/ */
/* /1*         create_info.ppEnabledExtensionNames = device_extensions.Data; *1/ */
/* /1*         err = vkCreateDevice(g_PhysicalDevice, &create_info, g_Allocator, &g_Device); *1/ */
/* /1*         check_vk_result(err); *1/ */
/* /1*         vkGetDeviceQueue(g_Device, g_QueueFamily, 0, &g_Queue); *1/ */
/* /1*     } *1/ */

/* /1*     // Create Descriptor Pool *1/ */
/* /1*     // The example only requires a single combined image sampler descriptor for the font image and only uses one descriptor set (for that) *1/ */
/* /1*     // If you wish to load e.g. additional textures you may need to alter pools sizes. *1/ */
/* /1*     { *1/ */
/* /1*         VkDescriptorPoolSize pool_sizes[] = *1/ */
/* /1*         { *1/ */
/* /1*             { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1 }, *1/ */
/* /1*         }; *1/ */
/* /1*         VkDescriptorPoolCreateInfo pool_info = {}; *1/ */
/* /1*         pool_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO; *1/ */
/* /1*         pool_info.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT; *1/ */
/* /1*         pool_info.maxSets = 1; *1/ */
/* /1*         pool_info.poolSizeCount = (uint32_t)IM_ARRAYSIZE(pool_sizes); *1/ */
/* /1*         pool_info.pPoolSizes = pool_sizes; *1/ */
/* /1*         err = vkCreateDescriptorPool(g_Device, &pool_info, g_Allocator, &g_DescriptorPool); *1/ */
/* /1*         check_vk_result(err); *1/ */
/* /1*     } *1/ */
/* /1* } *1/ */

/* /1* // All the ImGui_ImplVulkanH_XXX structures/functions are optional helpers used by the demo. *1/ */
/* /1* // Your real engine/app may not use them. *1/ */
/* /1* static void SetupVulkanWindow(ImGui_ImplVulkanH_Window* wd, VkSurfaceKHR surface, int width, int height) *1/ */
/* /1* { *1/ */
/* /1*     wd->Surface = surface; *1/ */

/* /1*     // Check for WSI support *1/ */
/* /1*     VkBool32 res; *1/ */
/* /1*     vkGetPhysicalDeviceSurfaceSupportKHR(g_PhysicalDevice, g_QueueFamily, wd->Surface, &res); *1/ */
/* /1*     if (res != VK_TRUE) *1/ */
/* /1*     { *1/ */
/* /1*         fprintf(stderr, "Error no WSI support on physical device 0\n"); *1/ */
/* /1*         exit(-1); *1/ */
/* /1*     } *1/ */

/* /1*     // Select Surface Format *1/ */
/* /1*     const VkFormat requestSurfaceImageFormat[] = { VK_FORMAT_B8G8R8A8_UNORM, VK_FORMAT_R8G8B8A8_UNORM, VK_FORMAT_B8G8R8_UNORM, VK_FORMAT_R8G8B8_UNORM }; *1/ */
/* /1*     const VkColorSpaceKHR requestSurfaceColorSpace = VK_COLORSPACE_SRGB_NONLINEAR_KHR; *1/ */
/* /1*     wd->SurfaceFormat = ImGui_ImplVulkanH_SelectSurfaceFormat(g_PhysicalDevice, wd->Surface, requestSurfaceImageFormat, (size_t)IM_ARRAYSIZE(requestSurfaceImageFormat), requestSurfaceColorSpace); *1/ */

/* /1*     // Select Present Mode *1/ */
/* /1* #ifdef APP_USE_UNLIMITED_FRAME_RATE *1/ */
/* /1*     VkPresentModeKHR present_modes[] = { VK_PRESENT_MODE_MAILBOX_KHR, VK_PRESENT_MODE_IMMEDIATE_KHR, VK_PRESENT_MODE_FIFO_KHR }; *1/ */
/* /1* #else *1/ */
/* /1*     VkPresentModeKHR present_modes[] = { VK_PRESENT_MODE_FIFO_KHR }; *1/ */
/* /1* #endif *1/ */
/* /1*     wd->PresentMode = ImGui_ImplVulkanH_SelectPresentMode(g_PhysicalDevice, wd->Surface, &present_modes[0], IM_ARRAYSIZE(present_modes)); *1/ */
/* /1*     //printf("[vulkan] Selected PresentMode = %d\n", wd->PresentMode); *1/ */

/* /1*     // Create SwapChain, RenderPass, Framebuffer, etc. *1/ */
/* /1*     IM_ASSERT(g_MinImageCount >= 2); *1/ */
/* /1*     ImGui_ImplVulkanH_CreateOrResizeWindow(g_Instance, g_PhysicalDevice, g_Device, wd, g_QueueFamily, g_Allocator, width, height, g_MinImageCount); *1/ */
/* /1* } *1/ */

/* /1* static void CleanupVulkan() *1/ */
/* /1* { *1/ */
/* /1*     vkDestroyDescriptorPool(g_Device, g_DescriptorPool, g_Allocator); *1/ */

/* /1* #ifdef APP_USE_VULKAN_DEBUG_REPORT *1/ */
/* /1*     // Remove the debug report callback *1/ */
/* /1*     auto f_vkDestroyDebugReportCallbackEXT = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(g_Instance, "vkDestroyDebugReportCallbackEXT"); *1/ */
/* /1*     f_vkDestroyDebugReportCallbackEXT(g_Instance, g_DebugReport, g_Allocator); *1/ */
/* /1* #endif // APP_USE_VULKAN_DEBUG_REPORT *1/ */

/* /1*     vkDestroyDevice(g_Device, g_Allocator); *1/ */
/* /1*     vkDestroyInstance(g_Instance, g_Allocator); *1/ */
/* /1* } *1/ */

/* /1* static void CleanupVulkanWindow() *1/ */
/* /1* { *1/ */
/* /1*     ImGui_ImplVulkanH_DestroyWindow(g_Instance, g_Device, &g_MainWindowData, g_Allocator); *1/ */
/* /1* } *1/ */

/* /1* static void FrameRender(ImGui_ImplVulkanH_Window* wd, ImDrawData* draw_data) *1/ */
/* /1* { *1/ */
/* /1*     VkResult err; *1/ */

/* /1*     VkSemaphore image_acquired_semaphore  = wd->FrameSemaphores[wd->SemaphoreIndex].ImageAcquiredSemaphore; *1/ */
/* /1*     VkSemaphore render_complete_semaphore = wd->FrameSemaphores[wd->SemaphoreIndex].RenderCompleteSemaphore; *1/ */
/* /1*     err = vkAcquireNextImageKHR(g_Device, wd->Swapchain, UINT64_MAX, image_acquired_semaphore, VK_NULL_HANDLE, &wd->FrameIndex); *1/ */
/* /1*     if (err == VK_ERROR_OUT_OF_DATE_KHR || err == VK_SUBOPTIMAL_KHR) *1/ */
/* /1*     { *1/ */
/* /1*         g_SwapChainRebuild = true; *1/ */
/* /1*         return; *1/ */
/* /1*     } *1/ */
/* /1*     check_vk_result(err); *1/ */

/* /1*     ImGui_ImplVulkanH_Frame* fd = &wd->Frames[wd->FrameIndex]; *1/ */
/* /1*     { *1/ */
/* /1*         err = vkWaitForFences(g_Device, 1, &fd->Fence, VK_TRUE, UINT64_MAX);    // wait indefinitely instead of periodically checking *1/ */
/* /1*         check_vk_result(err); *1/ */

/* /1*         err = vkResetFences(g_Device, 1, &fd->Fence); *1/ */
/* /1*         check_vk_result(err); *1/ */
/* /1*     } *1/ */
/* /1*     { *1/ */
/* /1*         err = vkResetCommandPool(g_Device, fd->CommandPool, 0); *1/ */
/* /1*         check_vk_result(err); *1/ */
/* /1*         VkCommandBufferBeginInfo info = {}; *1/ */
/* /1*         info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO; *1/ */
/* /1*         info.flags |= VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; *1/ */
/* /1*         err = vkBeginCommandBuffer(fd->CommandBuffer, &info); *1/ */
/* /1*         check_vk_result(err); *1/ */
/* /1*     } *1/ */
/* /1*     { *1/ */
/* /1*         VkRenderPassBeginInfo info = {}; *1/ */
/* /1*         info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO; *1/ */
/* /1*         info.renderPass = wd->RenderPass; *1/ */
/* /1*         info.framebuffer = fd->Framebuffer; *1/ */
/* /1*         info.renderArea.extent.width = wd->Width; *1/ */
/* /1*         info.renderArea.extent.height = wd->Height; *1/ */
/* /1*         info.clearValueCount = 1; *1/ */
/* /1*         info.pClearValues = &wd->ClearValue; *1/ */
/* /1*         vkCmdBeginRenderPass(fd->CommandBuffer, &info, VK_SUBPASS_CONTENTS_INLINE); *1/ */
/* /1*     } *1/ */

/* /1*     // Record dear imgui primitives into command buffer *1/ */
/* /1*     ImGui_ImplVulkan_RenderDrawData(draw_data, fd->CommandBuffer); *1/ */

/* /1*     // Submit command buffer *1/ */
/* /1*     vkCmdEndRenderPass(fd->CommandBuffer); *1/ */
/* /1*     { *1/ */
/* /1*         VkPipelineStageFlags wait_stage = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT; *1/ */
/* /1*         VkSubmitInfo info = {}; *1/ */
/* /1*         info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO; *1/ */
/* /1*         info.waitSemaphoreCount = 1; *1/ */
/* /1*         info.pWaitSemaphores = &image_acquired_semaphore; *1/ */
/* /1*         info.pWaitDstStageMask = &wait_stage; *1/ */
/* /1*         info.commandBufferCount = 1; *1/ */
/* /1*         info.pCommandBuffers = &fd->CommandBuffer; *1/ */
/* /1*         info.signalSemaphoreCount = 1; *1/ */
/* /1*         info.pSignalSemaphores = &render_complete_semaphore; *1/ */

/* /1*         err = vkEndCommandBuffer(fd->CommandBuffer); *1/ */
/* /1*         check_vk_result(err); *1/ */
/* /1*         err = vkQueueSubmit(g_Queue, 1, &info, fd->Fence); *1/ */
/* /1*         check_vk_result(err); *1/ */
/* /1*     } *1/ */
/* /1* } *1/ */

/* /1* static void FramePresent(ImGui_ImplVulkanH_Window* wd) *1/ */
/* /1* { *1/ */
/* /1*     if (g_SwapChainRebuild) *1/ */
/* /1*         return; *1/ */
/* /1*     VkSemaphore render_complete_semaphore = wd->FrameSemaphores[wd->SemaphoreIndex].RenderCompleteSemaphore; *1/ */
/* /1*     VkPresentInfoKHR info = {}; *1/ */
/* /1*     info.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR; *1/ */
/* /1*     info.waitSemaphoreCount = 1; *1/ */
/* /1*     info.pWaitSemaphores = &render_complete_semaphore; *1/ */
/* /1*     info.swapchainCount = 1; *1/ */
/* /1*     info.pSwapchains = &wd->Swapchain; *1/ */
/* /1*     info.pImageIndices = &wd->FrameIndex; *1/ */
/* /1*     VkResult err = vkQueuePresentKHR(g_Queue, &info); *1/ */
/* /1*     if (err == VK_ERROR_OUT_OF_DATE_KHR || err == VK_SUBOPTIMAL_KHR) *1/ */
/* /1*     { *1/ */
/* /1*         g_SwapChainRebuild = true; *1/ */
/* /1*         return; *1/ */
/* /1*     } *1/ */
/* /1*     check_vk_result(err); *1/ */
/* /1*     wd->SemaphoreIndex = (wd->SemaphoreIndex + 1) % wd->SemaphoreCount; // Now we can use the next set of semaphores *1/ */
/* /1* } *1/ */

/* /1* // Main code *1/ */
/* /1* int main(int, char**) *1/ */
/* /1* { *1/ */
/* /1*     glfwSetErrorCallback(glfw_error_callback); *1/ */
/* /1*     if (!glfwInit()) *1/ */
/* /1*         return 1; *1/ */

/* /1*     // Create window with Vulkan context *1/ */
/* /1*     glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); *1/ */
/* /1*     GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+Vulkan example", nullptr, nullptr); *1/ */
/* /1*     if (!glfwVulkanSupported()) *1/ */
/* /1*     { *1/ */
/* /1*         printf("GLFW: Vulkan Not Supported\n"); *1/ */
/* /1*         return 1; *1/ */
/* /1*     } *1/ */

/* /1*     ImVector<const char*> extensions; *1/ */
/* /1*     uint32_t extensions_count = 0; *1/ */
/* /1*     const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&extensions_count); *1/ */
/* /1*     for (uint32_t i = 0; i < extensions_count; i++) *1/ */
/* /1*         extensions.push_back(glfw_extensions[i]); *1/ */
/* /1*     SetupVulkan(extensions); *1/ */

/* /1*     // Create Window Surface *1/ */
/* /1*     VkSurfaceKHR surface; *1/ */
/* /1*     VkResult err = glfwCreateWindowSurface(g_Instance, window, g_Allocator, &surface); *1/ */
/* /1*     check_vk_result(err); *1/ */

/* /1*     // Create Framebuffers *1/ */
/* /1*     int w, h; *1/ */
/* /1*     glfwGetFramebufferSize(window, &w, &h); *1/ */
/* /1*     ImGui_ImplVulkanH_Window* wd = &g_MainWindowData; *1/ */
/* /1*     SetupVulkanWindow(wd, surface, w, h); *1/ */

/* /1*     // Setup Dear ImGui context *1/ */
/* /1*     IMGUI_CHECKVERSION(); *1/ */
/* /1*     ImGui::CreateContext(); *1/ */
/* /1*     ImGuiIO& io = ImGui::GetIO(); (void)io; *1/ */
/* /1*     io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls *1/ */
/* /1*     io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls *1/ */
/* /1*     io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking *1/ */
/* /1*     io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows *1/ */
/* /1*     //io.ConfigViewportsNoAutoMerge = true; *1/ */
/* /1*     //io.ConfigViewportsNoTaskBarIcon = true; *1/ */

/* /1*     // Setup Dear ImGui style *1/ */
/* /1*     ImGui::StyleColorsDark(); *1/ */
/* /1*     //ImGui::StyleColorsLight(); *1/ */

/* /1*     // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones. *1/ */
/* /1*     ImGuiStyle& style = ImGui::GetStyle(); *1/ */
/* /1*     if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) *1/ */
/* /1*     { *1/ */
/* /1*         style.WindowRounding = 0.0f; *1/ */
/* /1*         style.Colors[ImGuiCol_WindowBg].w = 1.0f; *1/ */
/* /1*     } *1/ */

/* /1*     // Setup Platform/Renderer backends *1/ */
/* /1*     ImGui_ImplGlfw_InitForVulkan(window, true); *1/ */
/* /1*     ImGui_ImplVulkan_InitInfo init_info = {}; *1/ */
/* /1*     init_info.Instance = g_Instance; *1/ */
/* /1*     init_info.PhysicalDevice = g_PhysicalDevice; *1/ */
/* /1*     init_info.Device = g_Device; *1/ */
/* /1*     init_info.QueueFamily = g_QueueFamily; *1/ */
/* /1*     init_info.Queue = g_Queue; *1/ */
/* /1*     init_info.PipelineCache = g_PipelineCache; *1/ */
/* /1*     init_info.DescriptorPool = g_DescriptorPool; *1/ */
/* /1*     init_info.RenderPass = wd->RenderPass; *1/ */
/* /1*     init_info.Subpass = 0; *1/ */
/* /1*     init_info.MinImageCount = g_MinImageCount; *1/ */
/* /1*     init_info.ImageCount = wd->ImageCount; *1/ */
/* /1*     init_info.MSAASamples = VK_SAMPLE_COUNT_1_BIT; *1/ */
/* /1*     init_info.Allocator = g_Allocator; *1/ */
/* /1*     init_info.CheckVkResultFn = check_vk_result; *1/ */
/* /1*     ImGui_ImplVulkan_Init(&init_info); *1/ */

/* /1*     // Load Fonts *1/ */
/* /1*     // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them. *1/ */
/* /1*     // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple. *1/ */
/* /1*     // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit). *1/ */
/* /1*     // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call. *1/ */
/* /1*     // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering. *1/ */
/* /1*     // - Read 'docs/FONTS.md' for more instructions and details. *1/ */
/* /1*     // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ ! *1/ */
/* /1*     //io.Fonts->AddFontDefault(); *1/ */
/* /1*     //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f); *1/ */
/* /1*     //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f); *1/ */
/* /1*     //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f); *1/ */
/* /1*     //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f); *1/ */
/* /1*     //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese()); *1/ */
/* /1*     //IM_ASSERT(font != nullptr); *1/ */

/* /1*     // Our state *1/ */
/* /1*     bool show_demo_window = true; *1/ */
/* /1*     bool show_another_window = false; *1/ */
/* /1*     ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f); *1/ */

/* /1*     // Main loop *1/ */
/* /1*     while (!glfwWindowShouldClose(window)) *1/ */
/* /1*     { *1/ */
/* /1*         // Poll and handle events (inputs, window resize, etc.) *1/ */
/* /1*         // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs. *1/ */
/* /1*         // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data. *1/ */
/* /1*         // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data. *1/ */
/* /1*         // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags. *1/ */
/* /1*         glfwPollEvents(); *1/ */

/* /1*         // Resize swap chain? *1/ */
/* /1*         int fb_width, fb_height; *1/ */
/* /1*         glfwGetFramebufferSize(window, &fb_width, &fb_height); *1/ */
/* /1*         if (fb_width > 0 && fb_height > 0 && (g_SwapChainRebuild || g_MainWindowData.Width != fb_width || g_MainWindowData.Height != fb_height)) *1/ */
/* /1*         { *1/ */
/* /1*             ImGui_ImplVulkan_SetMinImageCount(g_MinImageCount); *1/ */
/* /1*             ImGui_ImplVulkanH_CreateOrResizeWindow(g_Instance, g_PhysicalDevice, g_Device, &g_MainWindowData, g_QueueFamily, g_Allocator, fb_width, fb_height, g_MinImageCount); *1/ */
/* /1*             g_MainWindowData.FrameIndex = 0; *1/ */
/* /1*             g_SwapChainRebuild = false; *1/ */
/* /1*         } *1/ */
/* /1*         if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0) *1/ */
/* /1*         { *1/ */
/* /1*             ImGui_ImplGlfw_Sleep(10); *1/ */
/* /1*             continue; *1/ */
/* /1*         } *1/ */

/* /1*         // Start the Dear ImGui frame *1/ */
/* /1*         ImGui_ImplVulkan_NewFrame(); *1/ */
/* /1*         ImGui_ImplGlfw_NewFrame(); *1/ */
/* /1*         ImGui::NewFrame(); *1/ */

/* /1*         // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!). *1/ */
/* /1*         if (show_demo_window) *1/ */
/* /1*             ImGui::ShowDemoWindow(&show_demo_window); *1/ */

/* /1*         // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window. *1/ */
/* /1*         { *1/ */
/* /1*             static float f = 0.0f; *1/ */
/* /1*             static int counter = 0; *1/ */

/* /1*             ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it. *1/ */

/* /1*             ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too) *1/ */
/* /1*             ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state *1/ */
/* /1*             ImGui::Checkbox("Another Window", &show_another_window); *1/ */

/* /1*             ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f *1/ */
/* /1*             ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color *1/ */

/* /1*             if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated) *1/ */
/* /1*                 counter++; *1/ */
/* /1*             ImGui::SameLine(); *1/ */
/* /1*             ImGui::Text("counter = %d", counter); *1/ */

/* /1*             ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate); *1/ */
/* /1*             ImGui::End(); *1/ */
/* /1*         } *1/ */

/* /1*         // 3. Show another simple window. *1/ */
/* /1*         if (show_another_window) *1/ */
/* /1*         { *1/ */
/* /1*             ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked) *1/ */
/* /1*             ImGui::Text("Hello from another window!"); *1/ */
/* /1*             if (ImGui::Button("Close Me")) *1/ */
/* /1*                 show_another_window = false; *1/ */
/* /1*             ImGui::End(); *1/ */
/* /1*         } *1/ */

/* /1*         // Rendering *1/ */
/* /1*         ImGui::Render(); *1/ */
/* /1*         ImDrawData* main_draw_data = ImGui::GetDrawData(); *1/ */
/* /1*         const bool main_is_minimized = (main_draw_data->DisplaySize.x <= 0.0f || main_draw_data->DisplaySize.y <= 0.0f); *1/ */
/* /1*         wd->ClearValue.color.float32[0] = clear_color.x * clear_color.w; *1/ */
/* /1*         wd->ClearValue.color.float32[1] = clear_color.y * clear_color.w; *1/ */
/* /1*         wd->ClearValue.color.float32[2] = clear_color.z * clear_color.w; *1/ */
/* /1*         wd->ClearValue.color.float32[3] = clear_color.w; *1/ */
/* /1*         if (!main_is_minimized) *1/ */
/* /1*             FrameRender(wd, main_draw_data); *1/ */

/* /1*         // Update and Render additional Platform Windows *1/ */
/* /1*         if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) *1/ */
/* /1*         { *1/ */
/* /1*             ImGui::UpdatePlatformWindows(); *1/ */
/* /1*             ImGui::RenderPlatformWindowsDefault(); *1/ */
/* /1*         } *1/ */

/* /1*         // Present Main Platform Window *1/ */
/* /1*         if (!main_is_minimized) *1/ */
/* /1*             FramePresent(wd); *1/ */
/* /1*     } *1/ */

/* /1*     // Cleanup *1/ */
/* /1*     err = vkDeviceWaitIdle(g_Device); *1/ */
/* /1*     check_vk_result(err); *1/ */
/* /1*     ImGui_ImplVulkan_Shutdown(); *1/ */
/* /1*     ImGui_ImplGlfw_Shutdown(); *1/ */
/* /1*     ImGui::DestroyContext(); *1/ */

/* /1*     CleanupVulkanWindow(); *1/ */
/* /1*     CleanupVulkan(); *1/ */

/* /1*     glfwDestroyWindow(window); *1/ */
/* /1*     glfwTerminate(); *1/ */

/* /1*     return 0; *1/ */
/* /1* } *1/ */
#include "vulkan-engine/Application.hpp"
#include "vulkan-engine/EntryPoint.hpp"
#include "ExampleLayer.hpp"
#include <imgui/imgui.h>

MiniGameEngine::Application* MiniGameEngine::CreateApplication(int argc, char** argv){
	MiniGameEngine::ApplicationSpecification spec;
	spec.name = "Ray Tracing";

	MiniGameEngine::Application* app = new MiniGameEngine::Application(spec);
	app->pushLayer<ExampleLayer>();
	app->setMenubarCallback([app](){

		if (ImGui::BeginMenu("File")){
			if (ImGui::MenuItem("Exit")){
                printf("application closed!\n");
				app->close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}
