#include <iostream>
#include <fstream>
//+=
int main()
{
    std::ofstream fout("myImage.bmp", std::ios_base::out | std::ios_base::binary);
    std::uint16_t bm = 0x4D42;
    fout.write(reinterpret_cast<char*>(&bm), 2);

    std::uint32_t rec = 0x0000C61A;  //SIZE
    fout.write(reinterpret_cast<char*>(&rec),4);
    fout.seekp(4,fout.cur);
    rec = 0x0000007A; 
    fout.write(reinterpret_cast<char*>(&rec), 4);//BMP Header done 
    
    rec = 0x0000006C; //Start DIB Header
    fout.write(reinterpret_cast<char*>(&rec), 4);
    rec = 0x0000000A; // Width 
    fout.write(reinterpret_cast<char*>(&rec), 4);
    rec = 0x000000AA; // Height 
    fout.write(reinterpret_cast<char*>(&rec), 4);

    bm = 0x0001;
    fout.write(reinterpret_cast<char*>(&bm), 2);
    bm = 0x0020;
    fout.write(reinterpret_cast<char*>(&bm), 2);

    rec = 0x00000003; // No compression used
    fout.write(reinterpret_cast<char*>(&rec), 4);

    rec = 0x00000020; // Size of a raw
    fout.write(reinterpret_cast<char*>(&rec), 4); 

    rec = 0x00000B13;
    fout.write(reinterpret_cast<char*>(&rec), 4); 
    fout.write(reinterpret_cast<char*>(&rec), 4); //DPI res

    fout.seekp(8, fout.cur);  //Color pallete and important

    rec = 0x00FF0000; //Red channel
    fout.write(reinterpret_cast<char*>(&rec), 4);

    rec = 0x0000FF00; //Green channel
    fout.write(reinterpret_cast<char*>(&rec), 4);

    rec = 0x000000FF; //Blue channel
    fout.write(reinterpret_cast<char*>(&rec), 4);

    rec = 0xFF000000; //Alpha channel
    fout.write(reinterpret_cast<char*>(&rec), 4);
 
 
    rec = 0x57696E20; //little-endian "Win"
    fout.write(reinterpret_cast<char*>(&rec), 4);
    fout.seekp(36 + 12, fout.cur); //36+12 нулей 

    rec = 0xFF000000;
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 10; j++) {
             for (int k = 0; k < 10; k++) {
                fout.write(reinterpret_cast<char*>(&rec), 4);
            }
        }
        rec += 0x000F0F0F;
    }
 
    fout.close();
}
 
