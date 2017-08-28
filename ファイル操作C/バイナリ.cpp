#include <stdio.h>
#include <stdlib.h>
#include <string>
class soundData
{
public:
    soundData( )
    {
        FILE* fp = fopen( "test.b", "ab+" );
        char buf[sizeof( soundData )];
        memset( buf, 0, sizeof( soundData ) );
        fread( buf, 1, sizeof( soundData ), fp );
        hp = *(int*)( buf + 0 );
        mp = *(int*)( buf + sizeof( int ) );
        int a = 0;
    }
    ~soundData( )
    {
        auto fp = fopen( "test.b", "wb+" );
        char buf[sizeof( soundData )];
        memcpy( buf, &hp, sizeof( int ) );
        memcpy( buf + sizeof( int ), &mp, sizeof( int ) );
        fwrite( buf, 1, sizeof( soundData ), fp );
        int a = 0;
    }
    int hp;
    int mp;
};
int main( )
{
    // バイナリデータで自動保存する。
    {
        soundData d;
        d.hp = 100;
        d.mp = 500;
    }

    return 0;
}