let wrapper =  document.querySelector('#wrapper');
wrapper.dataset.mousedownat = 0;
wrapper.dataset.previous_movd = 0;

wrapper.addEventListener("mousedown",function(loc_md){
    
    wrapper.dataset.mousedownat = loc_md.clientX;
    
});

wrapper.addEventListener("mousemove",function(loc){

    if( parseFloat(wrapper.dataset.mousedownat)===0) 
       return;
     
 
  
    let mousemoved = ((((loc.clientX - parseFloat(wrapper.dataset.mousedownat))/window.innerWidth)*-200) + parseFloat(wrapper.dataset.previous_movd));    
    wrapper.dataset.previous = mousemoved;
    var card = document.querySelectorAll(".card");

    card.forEach(function(c){
       
        c.animate({
            objectPosition: `${100+mousemoved}% 50%`
        },{duration:1200,fill:"forwards"});
    })

    var cards = document.querySelector(".cards");
   
 
    cards.animate({
        transform: `translate(${mousemoved}%,0)`
    },{duration:1200,fill:"forwards"});
    
});

wrapper.addEventListener("mouseup",function(){
    
    wrapper.dataset.mousedownat = 0;
    wrapper.dataset.previous_movd = parseFloat(wrapper.dataset.previous);
    
})


VanillaTilt.init(document.querySelector("#img-pg2"), {
    max: 25,
    speed: 400,
    glare: true,
    "max-glare":1
});

