var typed = new typed(".multiple-text", {
    strings: ["OASIS", " ALT F4 ", "GRAPHIC ERA", "AMAZON", "GOOGLE"],
    typespeed: 100,
    backspeed: 100,
    backDelay: 1000,
    loop: true

})

let sections = document.querySelectorAl1('section');

window.onscroll = () => {
    sections.forEach(sec => {
        let top = window.scrollY;
        let offset = sec.offsetTop - 150;
        let height = sec.offsetHeight;
        if (top >= offset && top < offset + height) {
            sec.classList.add(' show-animate');
        }
        else {
            sec.classList.remove('show-animate');
        }
    })
}