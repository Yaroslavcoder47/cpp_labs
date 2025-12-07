import cv2
import numpy as np
import matplotlib.pyplot as plt
from collections import deque


def region_growing(image, threshold, seed_point):
    h, w = image.shape
    segmented_image = np.zeros_like(image, dtype=np.uint8)
    queue = deque([seed_point])
    segmented_image[seed_point] = 255
 
    current_mean = float(image[seed_point])
    region_size = 1
    
    neighbors = [(-1, 0), (1, 0), (0, -1), (0, 1), 
                 (-1, -1), (-1, 1), (1, -1), (1, 1)]

    while queue:
        y, x = queue.popleft()
        
        for dy, dx in neighbors:
            ny, nx = y + dy, x + dx
            
            if 0 <= ny < h and 0 <= nx < w and segmented_image[ny, nx] == 0:
                pixel_intensity = image[ny, nx]
                
                if abs(float(pixel_intensity) - current_mean) <= threshold:
                    segmented_image[ny, nx] = 255
                    queue.append((ny, nx))
                    
                    current_mean = (current_mean * region_size + pixel_intensity) / (region_size + 1)
                    region_size += 1
                    
    return segmented_image


def split_and_merge(image, threshold, min_size):
    img_float = image.astype(np.float64) / 255.0
    h, w = img_float.shape
    
    max_dim = max(h, w)
    next_pow_2 = 2 ** int(np.ceil(np.log2(max_dim)))
    
    padded_img = np.zeros((next_pow_2, next_pow_2), dtype=np.float64)
    padded_img[:h, :w] = img_float
    
    segmented_map = np.zeros_like(padded_img)

    def split(y, x, size):
        """
        Рекурсивная функция разделения.
        """
        # Извлекаем текущий регион
        roi = padded_img[y:y+size, x:x+size]
        
        # Считаем метрики однородности
        std_dev = np.std(roi)
        mean_val = np.mean(roi)
        
        if std_dev > threshold and size > min_size:
            new_size = size // 2
            split(y, x, new_size)                     # Top-Left
            split(y, x + new_size, new_size)          # Top-Right
            split(y + new_size, x, new_size)          # Bottom-Left
            split(y + new_size, x + new_size, new_size) # Bottom-Right
        else:
            segmented_map[y:y+size, x:x+size] = mean_val

    split(0, 0, next_pow_2)
    
    result = segmented_map[:h, :w]
    return (result * 255).astype(np.uint8)



image_path_1 = 'image3.jpg' 
color_img = cv2.imread(image_path_1)
image_path_2 = 'image4.png'
color_img_2 = cv2.imread(image_path_2)

if color_img is None or color_img_2 is None:
    print(f"Ошибка: Не удалось загрузить одно или оба изображения. Проверьте пути.")
else:
    grayscale_img = cv2.cvtColor(color_img, cv2.COLOR_BGR2GRAY)
    grayscale_img_2 = cv2.cvtColor(color_img_2, cv2.COLOR_BGR2GRAY)
    
    # --- МЕТОД РОСТА ОБЛАСТЕЙ ---
    rg_threshold = 30
    
    seed = (grayscale_img.shape[0] // 2, grayscale_img.shape[1] // 2)
    segmented_rg = region_growing(grayscale_img, rg_threshold, seed)

    # --- РАЗДЕЛЕНИЕ И СЛИЯНИЕ ---
    sm_threshold = 0.1
    sm_min_size = 4
    
    segmented_sm = split_and_merge(grayscale_img_2, sm_threshold, sm_min_size)

    fig, axes = plt.subplots(1, 4, figsize=(18, 5))    
    titles = [
        f'Исходное', 
        f'Рост областей (Порог={rg_threshold})', 
        f'Исходное',
        f'Разделение и слияние (Порог={sm_threshold}, Min Size={sm_min_size})'
    ]
    images = [grayscale_img, segmented_rg, grayscale_img_2, segmented_sm]
    
    for i in range(4):
        axes[i].imshow(images[i], cmap='gray')
        axes[i].set_title(titles[i], fontsize=10)
        axes[i].axis('off')
        
    plt.tight_layout()
    plt.show()