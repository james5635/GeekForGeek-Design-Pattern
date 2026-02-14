document.addEventListener("DOMContentLoaded", function () {

    const button = document.createElement("button");
    button.innerText = "☰";
    button.id = "sidebar-toggle-btn";
    document.body.appendChild(button);

    button.addEventListener("click", function () {
        document.documentElement.classList.toggle("sidebar-hidden");

        localStorage.setItem(
            "sidebarHidden",
            document.documentElement.classList.contains("sidebar-hidden")
        );
    });
});