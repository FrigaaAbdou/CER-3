import fitz  # PyMuPDF
import cv2
import numpy as np
from PIL import Image
import tkinter as tk
from tkinter import filedialog, messagebox
import os
import shutil

def detect_diagrams(pdf_path):
    output_dir = "detected_diagrams"
    os.makedirs(output_dir, exist_ok=True)

    doc = fitz.open(pdf_path)
    image_count = 0

    for i, page in enumerate(doc):
        pix = page.get_pixmap(matrix=fitz.Matrix(2, 2))
        img = Image.frombytes("RGB", [pix.width, pix.height], pix.samples)
        img_np = np.array(img)

        gray = cv2.cvtColor(img_np, cv2.COLOR_RGB2GRAY)
        blurred = cv2.GaussianBlur(gray, (5, 5), 0)
        edged = cv2.Canny(blurred, 50, 150)

        contours, _ = cv2.findContours(edged.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        for j, cnt in enumerate(contours):
            x, y, w, h = cv2.boundingRect(cnt)
            area = w * h
            if area > 20000 and area < (pix.width * pix.height * 0.8):
                cropped = img.crop((x, y, x + w, y + h))
                out_path = os.path.join(output_dir, f"diagram_p{i+1}_{j+1}.png")
                cropped.save(out_path)
                image_count += 1

    shutil.make_archive("auto_diagrams", 'zip', output_dir)
    return image_count

def select_pdf():
    file_path = filedialog.askopenfilename(filetypes=[("PDF Files", "*.pdf")])
    if file_path:
        count = detect_diagrams(file_path)
        messagebox.showinfo("Done", f"✅ {count} diagrams saved!\nCheck the 'auto_diagrams.zip' file.")
    else:
        messagebox.showwarning("No file", "Please select a PDF file.")

# GUI
app = tk.Tk()
app.title("Diagram Extractor")
app.geometry("300x150")

label = tk.Label(app, text="Select a PDF to extract diagrams", pady=20)
label.pack()

btn = tk.Button(app, text="Select PDF", command=select_pdf)
btn.pack()

app.mainloop()
