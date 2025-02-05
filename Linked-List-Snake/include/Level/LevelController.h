#pragma once
#include <vector>
#include "LevelModel.h"
#include "LevelView.h"
#include "Element/ElementData.h"

namespace Level
{
    class LevelView;
    class LevelModel;

    class LevelController
    {
    private:
        LevelModel* level_model;
        LevelView* level_view;

    public:
        LevelController();
        ~LevelController();

        void initialize();
        void update();
        void render();

        float getCellWidth();
        float getCellHeight();

        //const std::vector<Element::ElementData>& getElementDataList(int level_to_load);
        const std::vector<Element::ElementData>& getElementDataList(int level_to_load);
    };
}