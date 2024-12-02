# How to draw triangle

- CreateVkInstance
- Select a supported video card (VkPhysicalDevice).
- Create a VkDevice and VkQueue for drawing and presentation.
- Create window, window surface and swap chain
- Wrap swap chains in VkImageView images
- Create a rendering pass that defines rendering targets and usage
- Create frame buffers for the rendering pass
- Customize the graphics pipeline
- Allocate and record a command buffer with rendering commands for each possible image of the interchange chain.
- Draw frames by fetching images, sending the correct draw command buffer, and returning images back to the clipchain