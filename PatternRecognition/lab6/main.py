import cv2
import matplotlib.pyplot as plt
import numpy as np


def to_grayscale_manual(color_img):
    # BGR -> Gray: Gray = 0.114*B + 0.587*G + 0.299*R
    weights = np.array([0.114, 0.587, 0.299])
    grayscale_manual = np.dot(color_img[..., :3], weights).astype(np.uint8)
    return grayscale_manual


def binarize_manual(grayscale_img, threshold_value):
    binary_manual = np.zeros_like(grayscale_img, dtype=np.uint8)
    binary_manual[grayscale_img >= threshold_value] = 255
    return binary_manual


#--- Показ результатов ---
image_path = 'image.jpg'
color_img = cv2.imread(image_path)

if color_img is None:
    print(f"Ошибка: Не удалось загрузить изображение по пути: {image_path}. Проверьте путь.")
else:
    color_rgb = cv2.cvtColor(color_img, cv2.COLOR_BGR2RGB) 

    grayscale_manual_result = to_grayscale_manual(color_img)

    threshold = 100
    binary_manual_result = binarize_manual(grayscale_manual_result, threshold)

    
    titles = [
        'Исходное', 
        'Полутоновое',
        'Бинарное'
    ]
    images = [
        color_rgb, 
        grayscale_manual_result,
        binary_manual_result
    ]

    plt.figure(figsize=(15, 6))
    for i in range(3):
        plt.subplot(1, 3, i+1)
        cmap = 'gray' if i > 0 else None
        plt.imshow(images[i], cmap=cmap)
        plt.title(titles[i])
        plt.axis('off')
        
    plt.tight_layout()
    plt.show()