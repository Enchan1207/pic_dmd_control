//
// ドットマトリクスディスプレイの制御
//
#include <stdbool.h>
#include <string.h>
#include <xc.h>

#include "display.h"
#include "renderer.h"

void main(void) {
    // クロック設定
    OSCCONbits.IRCF = 0x0D;

    // LCD制御機能を無効化
    LCDEN = 0;

    // ディスプレイモジュールを初期化
    display_init();

    // オブジェクトレンダラ初期化
    renderer_init();

    // グローバル割り込み有効化
    INTCONbits.GIE = 1;

    // 表示の有効化
    display_setVisible(true);

    // 描画バッファ取得
    uint8_t* displayBuffer = display_getDrawBuffer();

    struct RenderObject* object_1 = &(renderObjects[0]);
    struct RenderObject* object_2 = &(renderObjects[1]);
    object_1->sx = 0;
    object_1->sy = 1;
    object_1->width = 3;
    object_1->height = 1;
    object_1->isVisible = true;

    object_2->sx = 3;
    object_2->sy = 5;
    object_2->width = 2;
    object_2->height = 3;
    object_2->isVisible = true;

    uint16_t lcnt = 0;
    while (true) {
        if (lcnt % 200 == 0) {
            object_1->sx++;
            object_2->sy++;
            if (object_1->sx > 10) {
                object_1->sx = -5;
            }
            if (object_2->sy > 10) {
                object_2->sy = -5;
            }

            display_setVisible(false);
            memset(displayBuffer, 0x00, 8);
            displayBuffer[0] = object_1->sx + 5;
            displayBuffer[7] = object_2->sy + 5;
            renderer_renderObjects(displayBuffer);
            display_setVisible(true);
        }

        lcnt++;
    }
}
