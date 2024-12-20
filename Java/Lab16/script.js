document.getElementById('studentForm').addEventListener('submit', function(event) {
    event.preventDefault(); 

    const name = document.getElementById('name').value;
    const surname = document.getElementById('surname').value;
    const email = document.getElementById('email').value;
    const course = document.getElementById('course').value;
    const active = document.getElementById('active').checked ? 'Да' : 'Нет';
    document.getElementById('outputName').textContent = name;
    document.getElementById('outputSurname').textContent = surname;
    document.getElementById('outputEmail').textContent = email;
    document.getElementById('outputCourse').textContent = course;
    document.getElementById('outputActive').textContent = active;
    const photoInput = document.getElementById('photo');
    if (photoInput.files && photoInput.files[0]) {
        const reader = new FileReader();
        reader.onload = function(e) {
            const outputPhoto = document.getElementById('outputPhoto');
            outputPhoto.src = e.target.result;
            outputPhoto.style.display = 'block';
        };
        reader.readAsDataURL(photoInput.files[0]);
    }

    document.getElementById('output').style.display = 'block';
});

