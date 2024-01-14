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

    uint16_t lcnt = 0;
    while (true) {
        // 更新要求が来ていればディスプレイを更新
        display_updateIfNeeded();

        // ループカウンタを表示
        displayBuffer[lcnt >> 13] = lcnt >> 8;
        lcnt++;
    }
}
