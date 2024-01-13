//
// ドットマトリクスディスプレイの制御
//
#include <stdbool.h>
#include <xc.h>

void main(void) {
    // internal oscillator configuration
    OSCCONbits.IRCF = 0x0D;

    // disable LCD feature
    LCDEN = 0;

    while (true) {
    }
}
