// Get the current date
var currentDate = new Date();

var options = { day: '2-digit', month: 'short', year: 'numeric' };
var formattedDate = currentDate.toLocaleDateString('en-US', options);

// Update the content of the HTML element with the formatted date
document.getElementById('currentDate').textContent = formattedDate;

 function showTime(){
    var date = new Date();
    var h = date.getHours(); // 0 - 23
    var m = date.getMinutes(); // 0 - 59
    var s = date.getSeconds(); // 0 - 59
    var session = "AM";
    
    if(h == 0){
        h = 12;
    }
    
    if(h > 12){
        h = h - 12;
        session = "PM";
    }
    
    h = (h < 10) ? "0" + h : h;
    m = (m < 10) ? "0" + m : m;
    s = (s < 10) ? "0" + s : s;
    
    var time = h + ":" + m + ":" + s + " " + session;
    document.getElementById("MyClockDisplay").innerText = time;
    document.getElementById("MyClockDisplay").textContent = time;
    
    setTimeout(showTime, 1000);
    
}

showTime();
document.getElementById("generateTimetable").addEventListener("click", function() {
    event.preventDefault(); 
  const totalSlots = parseInt(document.getElementById("totalSlots").value);
  const sections = parseInt(document.getElementById("sections").value);
  const instructors = parseInt(document.getElementById("instructors").value);

  const timetableTableBody = document.getElementById("timetableTable").getElementsByTagName("tbody")[0];
  timetableTableBody.innerHTML = ""; // Clear existing table data

  for (let i = 0; i < totalSlots; i++) {
    const timingValue = document.getElementById(`timing${i + 1}`).value;
    const sectionValue = document.getElementById(`section${i + 1}`).value;
    const instructorValue = document.getElementById(`instructor${i + 1}`).value;

    const row = document.createElement("tr");

    const timingCell = document.createElement("td");
    timingCell.textContent = timingValue;

    const sectionCell = document.createElement("td");
    sectionCell.textContent = sectionValue;

    const instructorCell = document.createElement("td");
    instructorCell.textContent = instructorValue;

    row.appendChild(timingCell);
    row.appendChild(sectionCell);
    row.appendChild(instructorCell);

    timetableTableBody.appendChild(row);
  }
});


function saveFieldValues() {
  const timingFields = document.getElementById("timingFields");
  const sectionFields = document.getElementById("sectionsFields");
  const instructorFields = document.getElementById("instructorsFields");

  const timingInputs = timingFields.querySelectorAll("input");
  const sectionInputs = sectionFields.querySelectorAll("input");
  const instructorInputs = instructorFields.querySelectorAll("input");

  timingInputs.forEach((input, index) => {
    localStorage.setItem(`timing${index + 1}`, input.value);
  });

  sectionInputs.forEach((input, index) => {
    localStorage.setItem(`section${index + 1}`, input.value);
  });

  instructorInputs.forEach((input, index) => {
    localStorage.setItem(`instructor${index + 1}`, input.value);
  });
}

function populateFieldValues() {
  console.log("Populating field values from Local Storage");
  const timingFields = document.getElementById("timingFields");
  const sectionFields = document.getElementById("sectionsFields");
  const instructorFields = document.getElementById("instructorsFields");

  const timingInputs = timingFields.querySelectorAll("input");
  const sectionInputs = sectionFields.querySelectorAll("input");
  const instructorInputs = instructorFields.querySelectorAll("input");

  timingInputs.forEach((input, index) => {
    const savedValue = localStorage.getItem(`timing${index + 1}`);
    if (savedValue) {
      input.value = savedValue;
    }
  });

  sectionInputs.forEach((input, index) => {
    const savedValue = localStorage.getItem(`section${index + 1}`);
    if (savedValue) {
      input.value = savedValue;
    }
  });

  instructorInputs.forEach((input, index) => {
    const savedValue = localStorage.getItem(`instructor${index + 1}`);
    if (savedValue) {
      input.value = savedValue;
    }
  });

  console.log("Field values populated from Local Storage");
}

document.getElementById("totalSlots").addEventListener("input", function(event) {
  const totalSlots = parseInt(event.target.value);
  const timingFields = document.getElementById("timingFields");

  // Remove any existing timing input fields
  timingFields.innerHTML = "";

  // Add timing input fields based on the total slots
  for (let i = 0; i < totalSlots; i++) {
    const label = document.createElement("label");
    label.setAttribute("for", `timing${i + 1}`);
    label.textContent = `Enter timing ${i + 1}:`;

    const input = document.createElement("input");
    input.setAttribute("type", "text");
    input.setAttribute("id", `timing${i + 1}`);
    input.setAttribute("name", `timing${i + 1}`);
    input.setAttribute("required", "");
    input.style.display = "block";
    timingFields.appendChild(label);
    timingFields.appendChild(input);
  }

  setTimeout(() => {
    saveFieldValues();
    populateFieldValues();
  }, 0);
});

document.getElementById("sections").addEventListener("input", function(event) {
  const sections = parseInt(event.target.value);
  const sectionsFields = document.getElementById("sectionsFields");

  // Remove any existing section input fields
  sectionsFields.innerHTML = "";

  // Add section input fields based on the total sections
  for (let i = 0; i < sections; i++) {
    const label = document.createElement("label");
    label.setAttribute("for", `section${i + 1}`);
    label.textContent = `Enter section Name ${i + 1}:`;

    const input = document.createElement("input");
    input.setAttribute("type", "text");
    input.setAttribute("id", `section${i + 1}`);
    input.setAttribute("name", `section${i + 1}`);
    input.setAttribute("required", "");
    input.style.display = "block";
    sectionsFields.appendChild(label);
    sectionsFields.appendChild(input);
  }

  setTimeout(() => {
    saveFieldValues();
    populateFieldValues();
  }, 0);
});

document.getElementById("instructors").addEventListener("input", function(event) {
  const instructors = parseInt(event.target.value);
  const instructorsFields = document.getElementById("instructorsFields");

  // Remove any existing instructor input fields
  instructorsFields.innerHTML = "";

  // Add instructor input fields based on the total instructors
  for (let i = 0; i < instructors; i++) {
    const label = document.createElement("label");
    label.setAttribute("for", `instructor${i + 1}`);
    label.textContent = `Enter instructor Name ${i + 1}:`;

    const input = document.createElement("input");
    input.setAttribute("type", "text");
    input.setAttribute("id", `instructor${i + 1}`);
    input.setAttribute("name", `instructor${i + 1}`);
    input.setAttribute("required", "");
    input.style.display = "block";
    instructorsFields.appendChild(label);
    instructorsFields.appendChild(input);
  }

  setTimeout(() => {
    saveFieldValues();
    populateFieldValues();
  }, 0);
});

document.getElementById("instructors").addEventListener("input", function(event) {

  const instructors = parseInt(event.target.value);
  const instructorsFields = document.getElementById("instructorscourse");

  // Remove any existing instructor input fields
  instructorsFields.innerHTML = "";

  // Add instructor input fields based on the total instructors
  for (let i = 0; i < instructors; i++) {
    const label = document.createElement("label");
    label.setAttribute("for", `instructor${i + 1}`);
    label.textContent = `Enter no.of courses taking by instructor${i + 1}:`;

    const input = document.createElement("input");
    input.setAttribute("type", "text");
    input.setAttribute("id", `instructor${i + 1}`);
    input.setAttribute("name", `instructor${i + 1}`);
    input.setAttribute("required", "");
    input.style.display = "block";
    instructorsFields.appendChild(label);
    instructorsFields.appendChild(input);
  }

  setTimeout(() => {
    saveFieldValues();
    populateFieldValues();
  }, 0);
});

window.addEventListener("load", populateFieldValues);
