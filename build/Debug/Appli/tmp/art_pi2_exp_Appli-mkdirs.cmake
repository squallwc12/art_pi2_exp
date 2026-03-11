# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "D:/Embedded_Software/GitHub/art_pi2_exp/Appli")
  file(MAKE_DIRECTORY "D:/Embedded_Software/GitHub/art_pi2_exp/Appli")
endif()
file(MAKE_DIRECTORY
  "D:/Embedded_Software/GitHub/art_pi2_exp/Appli/build"
  "D:/Embedded_Software/GitHub/art_pi2_exp/build/Debug/Appli"
  "D:/Embedded_Software/GitHub/art_pi2_exp/build/Debug/Appli/tmp"
  "D:/Embedded_Software/GitHub/art_pi2_exp/build/Debug/Appli/src/art_pi2_exp_Appli-stamp"
  "D:/Embedded_Software/GitHub/art_pi2_exp/build/Debug/Appli/src"
  "D:/Embedded_Software/GitHub/art_pi2_exp/build/Debug/Appli/src/art_pi2_exp_Appli-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Embedded_Software/GitHub/art_pi2_exp/build/Debug/Appli/src/art_pi2_exp_Appli-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Embedded_Software/GitHub/art_pi2_exp/build/Debug/Appli/src/art_pi2_exp_Appli-stamp${cfgdir}") # cfgdir has leading slash
endif()
