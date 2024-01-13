//
// ISR
//
#include <xc.h>

#include "display.h"

void __interrupt() Interrupt_interrupt(void) {
    // ディスプレイ描画更新タイマ
    if (TMR0IF == 1) {
        display_onUpdate();
    }
}
