#include <stdio.h>
#include <stdlib.h>
#include <string>
int main( )
{
    // �t�@�C�����J��
    // ����1 : �t�@�C���̑��΃p�X or �t���p�X(const char*)
    // ���΃p�X "test.txt" "texture/hoge.png"
    // ���΃p�X�����̊K�w�Ɉړ����鎞 "../sound"
    // �t���p�X "C:/Users/yuta/Documents/Visual Studio 2017/Projects/ConsoleApplication1/test.txt"
    // ����2 : �J���Ƃ��̃��[�h�ݒ�(const char*)
    // ���[�h�̎�� �ǂݍ��݂� "r" �ǂݍ��݂Ə������݂� "r+"
    // �Ԃ�l : �t�@�C���\����(FILE*)
    // if���̒��� 0�Ȃ�U 0�ȊO�͐^
    FILE* fp = fopen( "test.txt", "r+" );
    if ( fp ) // ��������t�@�C�����ǂݍ��߂܂�.
    {
        const int BUFFER_BYTE = 256;
        char buf[BUFFER_BYTE];
        // fopen �t�@�C�������s���ǂݍ��݂܂�
        // ����1 : �o�b�t�@�[(char*)
        // ����2 : �o�b�t�@�[�̃T�C�Y(int)
        // ����3 : �t�@�C���\����(FILE*)
        // �Ԃ�l : �ǂݍ��񂾂Ƃ��̐擪�|�C���^(char*)
        int enemyHp = atoi( fgets( buf, BUFFER_BYTE, fp ) );
        int enemyMp = atoi( fgets( buf, BUFFER_BYTE, fp ) );
        int enemyExperience = atoi( fgets( buf, BUFFER_BYTE, fp ) );

        // �����̍X�V����
        enemyHp -= 100;

        // �Z�[�u��������
        std::string data;
        data += std::to_string( enemyHp ) + "\n";
        data += std::to_string( enemyMp ) + "\n";
        data += std::to_string( enemyExperience ) + "\n";

        fclose( fp );
        // �t�@�C����������x�J�������܂��B
        FILE* fp = fopen( "test.txt", "w+" );
        if ( fp )
        {
            // �t�@�C�����ォ�炩�Ԃ��Ă�
            // ����1 : �������݂����f�[�^�̐擪�|�C���^
            // ����2 : �������ރf�[�^�^�̑傫��(char or int etx...)
            // ����3 : �������ރe�[�^���̂̑傫��(size_t)
            fwrite( data.c_str( ), sizeof( char ), data.size( ), fp );
            // �t�@�C�������
            fclose( fp );
        }
        else // �t�@�C�����ǂݍ��߂Ȃ�������.
        {
            printf( "�t�@�C�����ǂݍ��߂܂���ł����B" );
        }
    }
    else // �t�@�C�����ǂݍ��߂Ȃ�������.
    {
        printf( "�t�@�C�����ǂݍ��߂܂���ł����B" );
    }
    return 0;
}