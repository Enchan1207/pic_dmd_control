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
    volatile uint8_t* displayBuffer = display_getDrawBuffer();
    displayBuffer[2] = 0x50;
    displayBuffer[5] = 0x05;

    uint8_t lcnt = 0;
    while (true) {
        displayBuffer[0] = lcnt;

        if (lcnt % 64 == 0) {
            displayBuffer[1] = 0xFF;
        }
        if (lcnt % 192 == 0) {
            displayBuffer[1] = 0x00;
        }

        lcnt++;
        __delay_ms(1);
    }
}
