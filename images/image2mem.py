
from PIL import Image
import sys
#img = Image.open(r"C:\Users\mejia\OneDrive\Pictures\pythonsmall.jpg")


def generate_file(imagepath,filename="ImageFile",datatype="uint16_t",arrayname="imgArray"):
    img = Image.open(imagepath)
    f = open(filename + ".h","w")
    f.write("#ifndef {}".format(filename.upper()) + "_H_" + "\n")
    f.write("#define {}".format(filename.upper()) + "_H_" "\n\n\n")
    f.write("const {} {}[{}][{}] = ".format(datatype,arrayname,img.height,img.width) + "{\n")
    for y in range(0, img.height):
        s = "{"
        for x in range(0, img.width):
            (r, g, b) = img.getpixel( (x, y) )
            color565 = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3)
            # for right endiness, so ST7735_DrawImage would work
            color565 = ((color565 & 0xFF00) >> 8) | ((color565 & 0xFF) << 8)
            s += "0x{:04X},".format(color565)
        s += "},"
        f.write(s + "\n")
         
    f.write("};\n\n\n")
    f.write("#endif")
    f.close()

if __name__ == '__main__':


    image_path = sys.argv[1]
    file_name = sys.argv[2]
    generate_file(imagepath = image_path, filename = file_name, arrayname = file_name)