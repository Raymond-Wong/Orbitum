#ifndef _Config_H_
#define _Config_H_

#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 490

#define ORI_SCALE 0.2
#define ORI_CIRCLE_SCALE 1
#define SCALE_RATE 0.1
#define CIRCLE_RATE 1

#define BG_PATH "images/background_image.png"
#define FLOATING_LAYER_UI_PATH "FloatingLayerUI/FloatingLayerUI_1.ExportJson"
#define BTN_LAYER_UI_PATH "BtnUI/BtnUi_1.ExportJson"
#define MONSTER_PATH "monster.png"
#define CIRCLE_PATH "circle.png"
#define PLAYER_PATH "player.png"

#define BG_LAYER_PRIORITY 0
#define FLOATING_LAYER_PRIORITY 4
#define BLOCK_LAYER_PRIORITY 3
#define CIRCLE_LAYER_PRIORITY 2
#define BTN_LAYER_PRIORITY 1

class Config {

public:
    static bool isPause;

};

#endif