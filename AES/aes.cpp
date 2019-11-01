#include "aes.h"

Aes::Aes()
{

}

QString Aes::encrypt(QString text, QString key)
{
    int i = 0;
    for(int c = 0; c < BLOCK_SIZE; ++c){
      for(int r = 0; r < BLOCK_SIZE; ++r){
          text_block[r][c] = text.at(i).toLatin1();
          i++;
      }
    }

    qDebug()<<"Text";
    debugBlock(text_block);
    debugBlockHEX(text_block);

    i = 0;
    for(int c = 0; c < BLOCK_SIZE; ++c){
      for(int r = 0; r < BLOCK_SIZE; ++r){
          key_block[r][c] = key.at(i).toLatin1();
          i++;
      }
    }

    qDebug()<<"Key";
    debugBlock(key_block);
    debugBlockHEX(key_block);

    for(int r = 0; r < BLOCK_SIZE; ++r){
      for(int c = 0; c < BLOCK_SIZE; ++c){
          text_block[r][c] ^= key_block[r][c];
      }
    }

    qDebug()<<"Text XOR";
    debugBlock(text_block);
    debugBlockHEX(text_block);

    return QString();
}

void Aes::debugBlock(char block[4][4])
{
    qDebug()<<"Block";
    for(int c = 0; c < BLOCK_SIZE; ++c){
        qDebug() << block[c][0]<< block[c][1]<< block[c][2]<< block[c][3];
    }
}

void Aes::debugBlockHEX(char block[4][4])
{
    qDebug()<<"Block HEX";
    for(int c = 0; c < BLOCK_SIZE; ++c){
        qDebug() << QString::number(block[c][0], 16)<< QString::number(block[c][1], 16)<< QString::number(block[c][2], 16)<< QString::number(block[c][3], 16);
    }
}

