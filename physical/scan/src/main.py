import os
import sys
import pytesseract
from PIL import Image, ImageOps
pytesseract.pytesseract.tesseract_cmd = 'C:\\Program Files\\Tesseract-OCR\\tesseract.exe'

def get_commandline_args() -> dict:
    args: dict = {}

    if (len(sys.argv) == 3):
        if sys.argv[1] == "-cam":
            args["MODE"] = "cam"
        elif sys.argv[1] == "-in":
            if not (sys.argv[2]):
                print("You must provide a FILEPATH for file mode.")
                exit()
            else: args["FILEPATH"] = sys.argv[2]
            args["MODE"] = "file"
    
    return args

def get_cam_image() -> Image:
    print("todo")

def scan(filepath: str) -> None:
    image: Image = Image.open(filepath)
    (w, h) = image.size

    crop: tuple = (46, 0, 350, h)
    image: Image = image.crop(crop)
    work: Image = ImageOps.invert(image)

    (w, h) = work.size
    work: Image = work.resize((w * 10, h * 10))

    if not os.path.isdir("process"):
        os.mkdir("process")
    work.save("process/cropped_upscaled.png")

    text: str = pytesseract.image_to_string(work)
    lines: dict = text.splitlines()
    converted_lines: dict = [line for line in lines if line.strip() != ""]

    with open("output/out.turt", "w") as f:
        for line in converted_lines:
            f.write(f"{line}\n")

def main() -> None:
    if not os.path.isdir("input"):
        os.mkdir("input")
    if not os.path.isdir("output"):
        os.mkdir("output")
    args: str = get_commandline_args()
    if (args["MODE"] == "cam"):
        scan(get_cam_image())
    else: scan(args["FILEPATH"])

if __name__ == "__main__":
    main()