$(function() {

  $('.projectDescription').hide();

  var $clickedProject, $clickedProjectIcon;

  $('.projectTitle').on('click', function() {
    $clickedProject = $(this);
    $clickedProject.next().slideToggle(1000);
    $clickedProjectIcon = $(this).find('i');
    $clickedProjectIcon.toggleClass('fa-plus');
    $clickedProjectIcon.toggleClass('fa-minus');
  })

  $("a").on('click', function(event) {
    if (this.hash !== "") {
      event.preventDefault();
      var hash = this.hash;
      $('html, body').animate({
        scrollTop: $(hash).offset().top
      }, 1200, function(){
        window.location.hash = hash;
      });
    }
  });

});
