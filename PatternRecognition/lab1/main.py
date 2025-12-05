from tkinter import *
from tkinter import messagebox

root = Tk()
root.title("Геометрические фигуры")
root.geometry("700x700")


def clear_window():
    """Удаляет все виджеты с экрана для переключения меню."""
    for widget in root.winfo_children():
        widget.destroy()

def create_input_field(parent, label_text):
    """Создает подпись и поле ввода, возвращает объект Entry."""
    frame = Frame(parent)
    frame.pack(pady=5)
    Label(frame, text=label_text, width=15).pack(side=LEFT)
    entry = Entry(frame)
    entry.pack(side=LEFT)
    return entry


def draw_segment(canvas, inputs):
    try:
        coords = [int(entry.get()) for entry in inputs]
        x1, y1, x2, y2 = coords
        
        canvas.delete("all")
        canvas.create_line(x1, y1, x2, y2, fill="blue", width=2)
    except ValueError:
        messagebox.showerror("Ошибка", "Пожалуйста, введите корректные целые числа.")

def draw_circle(canvas, inputs):
    try:
        x, y, r = [int(entry.get()) for entry in inputs]
        canvas.delete("all")
        canvas.create_oval(x - r, y - r, x + r, y + r, outline="red", width=2)
    except ValueError:
        messagebox.showerror("Ошибка", "Пожалуйста, введите корректные целые числа.")

def draw_ellipse(canvas, inputs):
    try:
        x, y, a, b = [int(entry.get()) for entry in inputs]
        canvas.delete("all")
        canvas.create_oval(x - a // 2, y - b // 2, x + a // 2, y + b // 2, outline="green", width=2)
    except ValueError:
        messagebox.showerror("Ошибка", "Пожалуйста, введите корректные целые числа.")


def show_segment_screen():
    """Экран для рисования отрезка."""
    clear_window()
    Label(root, text="Рисуем Отрезок", font=("Arial", 16)).pack(pady=10)

    input_frame = Frame(root)
    input_frame.pack(pady=10)
    e1 = create_input_field(input_frame, "X1:")
    e2 = create_input_field(input_frame, "Y1:")
    e3 = create_input_field(input_frame, "X2:")
    e4 = create_input_field(input_frame, "Y2:")
    
    inputs = [e1, e2, e3, e4]

    canvas = Canvas(root, bg="white", width=350, height=350)
    canvas.pack(pady=10)

    btn_frame = Frame(root)
    btn_frame.pack(pady=10)
    
    Button(btn_frame, text="Нарисовать", bg="#dddddd", 
           command=lambda: draw_segment(canvas, inputs)).pack(side=LEFT, padx=10)
    
    Button(btn_frame, text="Назад в меню", 
           command=show_main_menu).pack(side=LEFT, padx=10)

def show_circle_screen():
    """Экран для рисования круга."""
    clear_window()
    Label(root, text="Рисуем Круг", font=("Arial", 16)).pack(pady=10)

    input_frame = Frame(root)
    input_frame.pack(pady=10)
    e1 = create_input_field(input_frame, "Центр X:")
    e2 = create_input_field(input_frame, "Центр Y:")
    e3 = create_input_field(input_frame, "Радиус R:")
    
    inputs = [e1, e2, e3]

    canvas = Canvas(root, bg="white", width=350, height=350)
    canvas.pack(pady=10)

    btn_frame = Frame(root)
    btn_frame.pack(pady=10)
    
    Button(btn_frame, text="Нарисовать", bg="#dddddd",
           command=lambda: draw_circle(canvas, inputs)).pack(side=LEFT, padx=10)
    
    Button(btn_frame, text="Назад в меню", 
           command=show_main_menu).pack(side=LEFT, padx=10)

def show_ellipse_screen():
    """Экран для рисования эллипса."""
    clear_window()
    Label(root, text="Рисуем Эллипс", font=("Arial", 16)).pack(pady=10)

    input_frame = Frame(root)
    input_frame.pack(pady=10)
    e1 = create_input_field(input_frame, "Центр X:")
    e2 = create_input_field(input_frame, "Центр Y:")
    e3 = create_input_field(input_frame, "Ширина (a):")
    e4 = create_input_field(input_frame, "Высота (b):")
    
    inputs = [e1, e2, e3, e4]

    canvas = Canvas(root, bg="white", width=350, height=350)
    canvas.pack(pady=10)

    btn_frame = Frame(root)
    btn_frame.pack(pady=10)
    
    Button(btn_frame, text="Нарисовать", bg="#dddddd",
           command=lambda: draw_ellipse(canvas, inputs)).pack(side=LEFT, padx=10)
    
    Button(btn_frame, text="Назад в меню", 
           command=show_main_menu).pack(side=LEFT, padx=10)


def show_main_menu():
    """Главное меню с выбором фигур."""
    clear_window()
    
    Label(root, text="Главное меню", font=("Arial", 20, "bold")).pack(pady=20)
    Label(root, text="Выберите фигуру для рисования:", font=("Arial", 12)).pack(pady=10)

    Button(root, text="Отрезок", font=("Arial", 14), width=15, 
           command=show_segment_screen).pack(pady=5)
    
    Button(root, text="Круг", font=("Arial", 14), width=15, 
           command=show_circle_screen).pack(pady=5)
    
    Button(root, text="Эллипс", font=("Arial", 14), width=15, 
           command=show_ellipse_screen).pack(pady=5)

    Button(root, text="Выход", font=("Arial", 12), fg="red", 
           command=root.quit).pack(pady=40)

if __name__ == "__main__":
    show_main_menu()
    root.mainloop()