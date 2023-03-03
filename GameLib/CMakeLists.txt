project(GameLib)

set(SOURCE_FILES GarbageBug.cpp GarbageBug.h NullBug.cpp NullBug.h Feature.cpp Feature.h RedundancyFly.cpp RedundancyFly.h FatBug.cpp FatBug.h Level0.h Level0.cpp Level1.h Level1.cpp Level2.h Level2.cpp Level3.h Level3.cpp)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
