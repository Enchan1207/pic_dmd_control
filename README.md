# ドットマトリクスディスプレイの制御

## Overview

ドットマトリクスディスプレイをいい感じに制御する

## Discussion

### 接続

実習で使用しているボードでは、ディスプレイとMCUとの接続は以下のようになっている:

 - 行: GPIO直結 (ディスプレイ上方よりA6, C0, C1, C2, C5, A7, B1, B2)
 - 列: 74HC595経由 (左端LSB, SCK=A5, D=A4)

実習では、1列目を表示する時にDに1を入れ、8列回るまで0を入れ続けている
= 最初に入力した1が各列を伝わっていく

### 実装

タイマ0とISRとDMDを実装で分けてる (`IntervalTimerForDMD`, `Interrupt.c`, `DotMatrixDisplay.c`)
でも正直ここまでする理由はないんだよな ISRはともかくタイマ0はこの子専用だし

## License

This repository is published under [MIT License](LICENSE).
