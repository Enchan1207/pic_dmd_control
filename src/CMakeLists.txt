#
# アプリケーションソース
#
cmake_minimum_required(VERSION 3.21)

add_executable(app)
target_sources(app PRIVATE
    main.c
    config.c
)
target_include_directories(app PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# リンカオプションの設定, 書込み・デバッグターゲットの追加
if(${BUILD_FOR_PIC})
    target_configure_for_pic(app)
endif()
