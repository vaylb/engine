// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_ANDROID_ANDROID_SURFACE_VULKAN_H_
#define FLUTTER_SHELL_PLATFORM_ANDROID_ANDROID_SURFACE_VULKAN_H_

#include <jni.h>
#include <memory>
#include "flutter/shell/platform/android/android_native_window.h"
#include "flutter/shell/platform/android/android_surface.h"
#include "flutter/vulkan/vulkan_window.h"
#include "lib/fxl/macros.h"

namespace shell {

class AndroidSurfaceVulkan : public AndroidSurface {
 public:
  AndroidSurfaceVulkan();

  ~AndroidSurfaceVulkan() override;

  // |shell::AndroidSurface|
  bool IsValid() const override;

  // |shell::AndroidSurface|
  std::unique_ptr<Surface> CreateGPUSurface() override;

  // |shell::AndroidSurface|
  void TeardownOnScreenContext() override;

  // |shell::AndroidSurface|
  bool OnScreenSurfaceResize(const SkISize& size) const override;

  // |shell::AndroidSurface|
  bool ResourceContextMakeCurrent() override;

  // |shell::AndroidSurface|
  bool SetNativeWindow(fxl::RefPtr<AndroidNativeWindow> window) override;

 private:
  fxl::RefPtr<vulkan::VulkanProcTable> proc_table_;
  fxl::RefPtr<AndroidNativeWindow> native_window_;

  FXL_DISALLOW_COPY_AND_ASSIGN(AndroidSurfaceVulkan);
};

}  // namespace shell

#endif  // FLUTTER_SHELL_PLATFORM_ANDROID_ANDROID_SURFACE_VULKAN_H_
