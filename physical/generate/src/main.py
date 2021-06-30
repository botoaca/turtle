import sys
import os
from datetime import date
from PIL import Image, ImageDraw, ImageFont

white: tuple = (255, 255, 255)
black: tuple = (0, 0, 0)

def get_commandline_args() -> dict:
    args: dict = {}

    if (len(sys.argv) == 7):
        if sys.argv[1] == "-in":
            args["FILEPATH"] = sys.argv[2]
        if sys.argv[3] == "-u":
            args["USERNAME"] = sys.argv[4]
        if sys.argv[5] == "-i":
            args["INSTITUTE"] = sys.argv[6]

    else:
        print("You must provide a FILEPATH, USERNAME and INSTITUTE")
        exit()
    
    return args
            

def get_lines(file_path: str) -> str:
    with open(file_path) as file:
        return file.readlines()

def generate(file_name: str, lines: str, username: str, institute: str) -> Image:
    date_str: str = date.today().strftime("%B %d, %Y")
    (w, h) = (500, 30)
    (count_pos, line_pos, info_pos) = (0, 55, w / 2 + 110)
    h_calculated: int = h
    for key in lines:
        h_calculated += 10
    h = h_calculated
    image = Image.new("RGB", (w, h), black)
    draw = ImageDraw.Draw(image)

    # Draw lines
    draw.line([(w - w / 2 + 100, h), (w / 2 + 100, 0)], white, 2) # info
    draw.line([(45, h), (45, 0)], white, 2)                       # line count

    # Draw code
    y: int = 0
    inc: int = 1
    for key in lines:
        draw.text((line_pos, y), key, white)
        draw.text((count_pos, y), str(inc), white)
        inc = inc + 1
        y = y + 10

    # Draw info
    info = "\n".join([
        f"FILE NAME: {file_name}",
        f"LINES: {inc - 1}",
        f"USERNAME: {username}",
        f"INSTITUTE: {institute}",
        f"DATE: {date_str}",
    ])
    draw.text((info_pos, 10), info, white)

    if inc > 100:
        print("This program is longer than 99 lines.")
        exit()

    return image

def main() -> None:
    if not os.path.isdir("input"):
        os.mkdir("input")
    if not os.path.isdir("output"):
        os.mkdir("output")
    args: str = get_commandline_args()
    file_name: str = os.path.basename(args["FILEPATH"])
    lines: str = get_lines(args["FILEPATH"])
    username: str = args["USERNAME"]
    institute: str = args["INSTITUTE"]
    generate(file_name, lines, username, institute).save(f'output/{file_name}.png')

if __name__ == "__main__": 
    main()