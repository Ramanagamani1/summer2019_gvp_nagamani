"""classproject URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.conf import settings
from django.conf.urls.static import static
from django.contrib.staticfiles.urls import staticfiles_urlpatterns
from django.urls import include, path  # For django versions from
from onlineapp import views
from onlineapp.views.college import CollegeView
from onlineapp.views.college import AddCollegeView,AddStudentView
from onlineapp.views.auth import *
from onlineapp.views.college_list import *
from onlineapp.views.student_list import *
from onlineapp.views.sample import *


urlpatterns = [
    path('admin/', admin.site.urls),
    #path('hello/', views.hello_world),
    #path('hello1/',views.hello),
    #path('college/',views.get_my_college),
    #path('colleges/',views.get_all_colleges),
    #path('getcolleges/',views.get_colleges),
    #path('studentnames/<int:id>',views.student_names),
    #path('collegeform/',views.collegeform),
    #path("",lambda req: redirect('colleges/',permanent=True))
    #path(r'api/token/', views.obtain_auth_token),
    path(r'api/v1/token/', CustomAuthToken.as_view()),
    path("myview/",my_first_view),
    path("api/v1/colleges/",rest_CollegeList),
    path(r"api/v1/colleges/<int:id>/",rest_CollegeDetails),
    path(r"api/v1/colleges/<int:id>/students/",rest_StudentList.as_view()),
    path(r"api/v1/colleges/<int:id>/students/<int:sid>/",rest_StudentDetails.as_view()),
    path('colleges/',views.college.CollegeView.as_view(),name="colleges_html"),
    path('colleges/<int:id>/',views.college.CollegeView.as_view(),name="student_html"),
    path('colleges/<str:acronym>/',views.college.CollegeView.as_view(),name="student_html"),
    path("college/add/",AddCollegeView.as_view(),name="addcolleges"),
    path(r"colleges/<int:pk>/edit",AddCollegeView.as_view(),name="edit_college"),
    path(r"colleges/<int:pk>/delete",AddCollegeView.as_view(),name="delete_college"),
    path("colleges/<int:pk>/add/",AddStudentView.as_view(),name="addstudent"),
    path("student/<int:pk>/edit",AddStudentView.as_view(),name="edit_student"),
    path("student/<int:pk>/delete", AddStudentView.as_view(),name="delete_student"),
    path(r'login/',LoginView.as_view(),name="loginform"),
    path(r'signup/',SignupView.as_view(),name="signupform"),
    path(r'logout/',logout_user,name="logout")

]+ static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)

if settings.DEBUG:
    import debug_toolbar
    urlpatterns = [

        path('__debug__/', include(debug_toolbar.urls)),

        # For django versions before 2.0:
        # url(r'^__debug__/', include(debug_toolbar.urls)),



    ] + urlpatterns