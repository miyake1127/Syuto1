#include <stdio.h>
#include <stdlib.h>
#include <string>
bool read( std::string const& relativeFilePath, std::string* data )
{
    // ファイルを開く
    // 引数1 : ファイルの相対パス or フルパス(const char*)
    // 相対パス "test.txt" "texture/hoge.png"
    // 相対パスから上の階層に移動する時 "../sound"
    // フルパス "C:/Users/yuta/Documents/Visual Studio 2017/Projects/ConsoleApplication1/test.txt"
    // 引数2 : 開くときのモード設定(const char*)
    // モードの種類 読み込みは "r" 読み込みと書き込みは "r+"
    // 返り値 : ファイル構造体(FILE*)
    FILE* fp = fopen( relativeFilePath.c_str( ), "r+" );
    if ( !fp ) return false;

    const size_t BUFFER_BYTE = 1024;
    char buffer[BUFFER_BYTE];
    // freadは一気にファイルから読み込める関数です。
    fread( buffer, 1, BUFFER_BYTE, fp );
    *data = buffer;
    fclose( fp );
    return true;
}
bool write( std::string const& relativeFilePath, std::string const& data )
{
    FILE* fp = fopen( relativeFilePath.c_str( ), "w+" );
    if ( !fp ) return false;

    fwrite( data.c_str( ), sizeof( char ), data.size( ), fp );
    fclose( fp );
    return true;
}
std::string lineCut( std::string* data )
{
    size_t pos = data->find( '\n' );
    auto str = data->substr( 0, pos );
    *data = data->substr( pos + sizeof( '\n' ), std::string::npos );
    return str;
}
class sound
{
public:
    // 汚いけどわかりやすい
    void read1( std::string const& data )
    {
        std::string writableData = data;

        size_t foundByte = writableData.find( '\n' );
        auto hps = writableData.substr( 0, foundByte );
        writableData = writableData.substr( foundByte + sizeof( '\n' ), std::string::npos );

        foundByte = writableData.find( '\n' );
        auto mps = writableData.substr( 0, foundByte );
        writableData = writableData.substr( foundByte + sizeof( '\n' ), std::string::npos );

        foundByte = writableData.find( '\n' );
        auto experiences = writableData.substr( 0, foundByte );
        writableData = writableData.substr( foundByte + sizeof( '\n' ), std::string::npos );
    }
    // 一番処理速度が良い
    void read2( std::string const& data )
    {
        size_t sumByte = 0;

        size_t hpFoundByte = data.find( '\n', 0 );
        auto hps = data.substr( sumByte, hpFoundByte - sumByte );
        sumByte += hpFoundByte - sumByte + sizeof( '\n' );

        size_t mpFoundByte = data.find( '\n', hpFoundByte + sizeof( '\n' ) );
        auto mps = data.substr( sumByte, mpFoundByte - sumByte );
        sumByte += mpFoundByte - sumByte + sizeof( '\n' );

        size_t experienceFoundByte = data.find( '\n', mpFoundByte + sizeof( '\n' ) );
        auto experiences = data.substr( sumByte, experienceFoundByte - sumByte );
        sumByte += experienceFoundByte - sumByte + sizeof( '\n' );

        hp = std::stoi( hps );
        mp = std::stoi( mps );
        experience = std::stoi( experiences );
    }
    // コードを読みやすい
    void read3( std::string const& data )
    {
        std::string writableData = data;
        auto hps = lineCut( &writableData );
        auto mps = lineCut( &writableData );
        auto experiences = lineCut( &writableData );

        hp = std::stoi( hps );
        mp = std::stoi( mps );
        experience = std::stoi( experiences );
    }
    sound( std::string const& relativeFilePath )
    {
        this->relativeFilePath = relativeFilePath;
        std::string data;
        if ( read( relativeFilePath, &data ) )
        {
            read3( data );
        }
    }
    // 保存
    ~sound( )
    {
        std::string data;
        data += std::to_string( hp ) + "\n";
        data += std::to_string( mp ) + "\n";
        data += std::to_string( experience ) + "\n";
        write( relativeFilePath, data );
    }
    std::string relativeFilePath;
    int hp;
    int mp;
    int experience;
};
int main( )
{
    // コンストラクタでデータを自動で読み込み、デストラクタで自動保存する。
    {
        sound e( "autosave.txt" );
        e.hp -= 20;
    }

    return 0;
}