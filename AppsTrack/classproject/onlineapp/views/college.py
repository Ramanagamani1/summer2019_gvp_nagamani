from django.views import View
from onlineapp.models import College,Student,MockTest1
from django.shortcuts import render,redirect
from django import forms
from django.shortcuts import get_object_or_404
from onlineapp.forms.colleges import AddCollege
from onlineapp.forms.students import AddStudent,AddStudentMarks
from django.urls import resolve
from django.contrib.auth.mixins import LoginRequiredMixin

class CollegeView(LoginRequiredMixin,View):
    login_url='/login/'
    def get(self,request,*args,**kwargs):
        if kwargs:

            #college=get_object_or_404(College,**kwargs)
            college=College.objects.get(**kwargs)
            students=list(college.student_set.order_by("-mocktest1__total"))
            #import ipdb
            #ipdb.set_trace()
            return render(
                request,
                template_name="onlineapp/student.html",

                context={

                    'college':college,
                    'students':students,

                    'user_permissions':request.user.get_all_permissions(),
                    'title':'Students from {} | Mentor App'.format(college.name)
                }
            )

        colleges=College.objects.all()
        return render(
            request,
            template_name="onlineapp/colleges.html",
            context={
                'colleges':colleges,
                'user_permissions': request.user.get_all_permissions(),
                'title':'All colleges | Mentor App'
            }
        )


class AddCollegeView(LoginRequiredMixin,View):
    login_url = '/login/'
    def get(self, request, **kwargs):
        form=AddCollege()
        if resolve(request.path_info).url_name=='edit_college':
            college=College.objects.get(**kwargs)
            form=AddCollege(instance=college)
            return render(request, template_name='onlineapp/addcollege.html',
                      context={'form':form})

        if resolve(request.path_info).url_name=='delete_college':
             c=College.objects.get(pk=kwargs.get('pk')).delete()
             return redirect('colleges_html')

        return render(request, template_name='onlineapp/addcollege.html',
                      context={'form': form})

    def post(self, request, **kwargs):
        form = AddCollege(request.POST)
        if resolve(request.path_info).url_name=='delete_college':
             c=College.objects.get(pk=kwargs.get('pk')).delete()
             return redirect('colleges_html')

        if resolve(request.path_info).url_name=='edit_college':
            college=College.objects.get(**kwargs)
            form=AddCollege(request.POST,instance=college)
            if form.is_valid():
                form.save()
                return redirect('colleges_html')


        if form.is_valid():
            form.save()
            return redirect('colleges_html')

        return render(
            request,
            template_name='onlineapp/addcollege.html',

            context={'form':form,'title':'Add College | MentorApp','user_permissions':request.user.get_all_permissions()}
        )
        pass


class AddStudentView(LoginRequiredMixin,View):
    login_url = '/login/'
    def get(self,request,**kwargs):

        if resolve(request.path_info).url_name=='delete_student':
             Student.objects.get(id=kwargs.get('pk')).delete()
             return redirect('colleges_html')

        form1=AddStudent()
        form2=AddStudentMarks()
        if resolve(request.path_info).url_name=='edit_student':
            #student=Student.objects.get(id=kwargs.get('student_id'))
            #score=MockTest1.objects.get(student_id=kwargs.get('student_id'))
            s_id=Student.objects.get(id=kwargs['pk'])
            form1=AddStudent(instance=s_id)
            m_id=MockTest1.objects.get(student=s_id)
            form2=AddStudentMarks(instance=m_id)
            return render(request, template_name='onlineapp/addstudent.html',
                      context={'form1':form1,'form2':form2})



        return render(request,template_name="onlineapp/addstudent.html",context={'form1':form1,'form2':form2,'user_permissions':request.user.get_all_permissions()})

    def post(self,request,**kwargs):
        college=get_object_or_404(College,id=kwargs.get('pk'))
        form1=AddStudent(request.POST)
        form2=AddStudentMarks(request.POST)

        if resolve(request.path_info).url_name == 'edit_student':
            s_id = Student.objects.get(id=kwargs['pk'])
            form1 = AddStudent(instance=s_id)
            m_id = MockTest1.objects.get(student=s_id)
            form2 = AddStudentMarks(instance=m_id)
            if form1.is_valid() and form2.is_valid():
                form1.save()
                form2.save()
                return redirect('student_html',kwargs['pk'])

        if form1.is_valid() and form2.is_valid():
                form1=form1.save(commit=False)
                form1.college=college
                form1.save()
                form2=form2.save(commit=False)
                form2.total=form2.problem1+form2.problem2+form2.problem3+form2.problem4
                form2.student=Student.objects.get(id=form1.id)
                form2.save()
                return redirect('student_html',kwargs['pk'])

        #return self.update_
        return render(
            request,
            template_name='onlineapp/addstudent.html',
            context={'form1':form1,'form2':form2,'title':'Add Student | MentorApp','user_permissions':request.user.get_all_permissions()}
        )
        pass