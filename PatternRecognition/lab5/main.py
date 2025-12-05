import cv2
import matplotlib.pyplot as plt
import numpy as np

PATH = "image3.jpg" 

def plot_histogram(image, title, ax):
    """
    Строит гистограмму для одноканального изображения.
    """
    hist = cv2.calcHist([image], [0], None, [256], [0, 256])
    
    ax.plot(hist, color='black', linewidth=1.5)
    ax.fill_between(range(256), hist.flatten(), color='#4682B4', alpha=0.5) 
    
    ax.set_title(title, fontsize=14, weight='bold')
    ax.set_xlabel("Интенсивность пикселя (0-255)", fontsize=10)
    ax.set_ylabel("Кол-во пикселей", fontsize=10)
    ax.set_xlim([0, 256])
    ax.grid(axis='y', linestyle='--', alpha=0.6)


def show_image_and_histogram(image, image_title):
    """
    Отображает изображение и его гистограмму в одной строке.
    """
    fig, axes = plt.subplots(1, 2, figsize=(14, 6))
    
    axes[0].imshow(image, cmap='gray')
    axes[0].set_title(image_title, fontsize=16)
    axes[0].axis('off') # Убираем оси для изображения
    
    plot_histogram(image, f'Гистограмма', axes[1])
    
    plt.suptitle(f"Изображение и анализ распределения интенсивности", fontsize=18, y=1.05)
    plt.tight_layout(rect=[0, 0, 1, 0.95])
    plt.show()


if __name__ == "__main__":
    
    image = cv2.imread(PATH)
    
    if image is None:
        print("Ошибка: Не удалось загрузить изображение по указанному пути. Создаю тестовый градиент.")
        
        gray_image = np.zeros((300, 400), dtype=np.uint8)
        for i in range(400):
            gray_image[:, i] = np.clip(i * 255 / 400, 0, 255)
        image_title = "Тестовый градиент (равномерное распределение)"
        
    else:
        gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        image_title = f"Исходное изображение: {PATH}"
    
    show_image_and_histogram(gray_image, image_title)