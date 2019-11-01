#define BLOCK_SIZE 4

#ifndef AES_H
#define AES_H
#include <QString>
#include <QDebug>

class Aes
{
    char text_block[BLOCK_SIZE][BLOCK_SIZE];
    char key_block[BLOCK_SIZE][BLOCK_SIZE];
public:
    Aes();
    QString encrypt(QString text, QString key);
private:
    void debugBlock(char block[4][4]);
    void debugBlockHEX(char block[4][4]);

};

#endif // AES_H
