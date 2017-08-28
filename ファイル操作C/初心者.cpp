#include <stdio.h>
#include <stdlib.h>
#include <string>
int main( )
{
    // ファイルを開く
    // 引数1 : ファイルの相対パス or フルパス(const char*)
    // 相対パス "test.txt" "texture/hoge.png"
    // 相対パスから上の階層に移動する時 "../sound"
    // フルパス "C:/Users/yuta/Documents/Visual Studio 2017/Projects/ConsoleApplication1/test.txt"
    // 引数2 : 開くときのモード設定(const char*)
    // モードの種類 読み込みは "r" 読み込みと書き込みは "r+"
    // 返り値 : ファイル構造体(FILE*)
    // if文の中が 0なら偽 0以外は真
    FILE* fp = fopen( "test.txt", "r+" );
    if ( fp ) // ここからファイルが読み込めます.
    {
        const int BUFFER_BYTE = 256;
        char buf[BUFFER_BYTE];
        // fopen ファイルから一行ずつ読み込みます
        // 引数1 : バッファー(char*)
        // 引数2 : バッファーのサイズ(int)
        // 引数3 : ファイル構造体(FILE*)
        // 返り値 : 読み込んだときの先頭ポインタ(char*)
        int enemyHp = atoi( fgets( buf, BUFFER_BYTE, fp ) );
        int enemyMp = atoi( fgets( buf, BUFFER_BYTE, fp ) );
        int enemyExperience = atoi( fgets( buf, BUFFER_BYTE, fp ) );

        // 何かの更新処理
        enemyHp -= 100;

        // セーブしたい時
        std::string data;
        data += std::to_string( enemyHp ) + "\n";
        data += std::to_string( enemyMp ) + "\n";
        data += std::to_string( enemyExperience ) + "\n";

        fclose( fp );
        // ファイルをもう一度開き直します。
        FILE* fp = fopen( "test.txt", "w+" );
        if ( fp )
        {
            // ファイルを上からかぶせてる
            // 引数1 : 書き込みたいデータの先頭ポインタ
            // 引数2 : 書き込むデータ型の大きさ(char or int etx...)
            // 引数3 : 書き込むテータ自体の大きさ(size_t)
            fwrite( data.c_str( ), sizeof( char ), data.size( ), fp );
            // ファイルを閉じる
            fclose( fp );
        }
        else // ファイルが読み込めなかったら.
        {
            printf( "ファイルが読み込めませんでした。" );
        }
    }
    else // ファイルが読み込めなかったら.
    {
        printf( "ファイルが読み込めませんでした。" );
    }
    return 0;
}