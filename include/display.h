//
// ドットマトリクスディスプレイ
//
#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief ディスプレイモジュール初期化
 */
void display_init(void);

/**
 * @brief 表示状態を設定
 *
 * @param state 状態(表示/非表示)
 * @note 表示を有効にするとタイマ0が動作を開始します。
 */
void display_setVisible(bool state);

/**
 * @brief ディスプレイの更新要求をセット
 * @note ISRから呼ばれることを想定しています。内部の更新要求フラグをセットします。
 */
void display_setNeedsUpdate(void);

/**
 * @brief 表示内容の更新
 * @note 列を移動し、データを反映します。
 */
void display_updateIfNeeded(void);

/**
 * @brief 描画バッファを取得
 *
 * @return uint8_t* 描画バッファへのポインタ
 */
volatile uint8_t* display_getDrawBuffer(void);

#endif /* DISPLAY_H */
