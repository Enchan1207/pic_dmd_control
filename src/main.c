//
// ドットマトリクスディスプレイの制御
//
#include <stdbool.h>
#include <xc.h>

#include "display.h"

void main(void) {
    // クロック設定
    OSCCONbits.IRCF = 0x0D;

    // LCD制御機能を無効化
    LCDEN = 0;

    // ディスプレイモジュールを初期化
    display_init();

    // グローバル割り込み有効化
    INTCONbits.GIE = 1;

    // 表示の有効化
    display_setVisible(true);

    // 描画バッファ取得+編集
    uint8_t* displayBuffer = display_getDrawBuffer();
    displayBuffer[2] = 0x50;
    displayBuffer[5] = 0x05;

    while (true) {
    }
}
