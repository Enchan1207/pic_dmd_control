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

    // 描画バッファ取得
    volatile uint8_t* displayBuffer = display_getDrawBuffer();

    uint8_t lcnt = 0;
    while (true) {
        // 一列目にループカウンタを表示
        displayBuffer[0] = lcnt;

        // lcntが16未満なら3列目を全点灯
        if (lcnt >> 4 == 0) {
            displayBuffer[2] = 0xFF;
        } else {
            displayBuffer[2] = 0x00;
        }

        // カウンタは1msごとに増加
        lcnt++;
        __delay_ms(1);
    }
}
