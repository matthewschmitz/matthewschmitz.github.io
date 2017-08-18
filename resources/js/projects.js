$(function() {

  $('.contentDescription').hide();

  var $clickedProject, $clickedProjectIcon;

  $('.contentTitle').on('click', function() {
    $clickedProject = $(this);
    $clickedProject.next().slideToggle(1000);
    $clickedProjectIcon = $(this).find('i');
    $clickedProjectIcon.toggleClass('fa-plus');
    $clickedProjectIcon.toggleClass('fa-minus');
  })

});
