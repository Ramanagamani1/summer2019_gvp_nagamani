import os

def main():
    os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'classproject.settings')
    import django
    django.setup()
    from onlineapp.models import College, MockTest1, Student
    c=College.objects.all()
    print(c)
    for r in c:
        print(r.name,r.location,r.acronym,r.contact)

    c=College.objects.filter(location="Hyderabad").count()
    x=College.objects.values('location').filter(location='vizag').count()
    print(c)

    x=College.objects.order_by('acronym')
    #to get list in reverse
    x = College.objects.order_by('-acronym')[:5]

    #to get count of colleges by location
    from django.db.models import Count
    College.objects.values('location').annotate(dcount=Count('location'))

    #sort on count of colleges
    College.objects.values('location').annotate(dcount=Count('location')).order_by('-dcount')

    #to print colleges having dropped_outs
    Student.objects.filter(dropped_out=True).values('college__name').distinct();

    #query to print college and number of students including dropouts
    c=Student.objects.all()
    c=c.values('college__name').annotate(dcount=Count('college__name')).distinct().order_by('-dcount')
    #c=c.values('college__acronym').annotate(Count('id'))


    #query to print college and number of students excluding dropouts
    c=Student.objects.filter(dropped_out=False)
    c=c.values('college__name').annotate(dcount=Count('college__name')).distinct().order_by('-dcount')

    #query to print no of students in a location
    c = Student.objects.all()
    c = c.values('college__location').annotate(dcount=Count('college__location')).distinct().order_by('-dcount')

    #query to get location with maximum number of students
    c = Student.objects.all()
    c = c.values('college__location').annotate(dcount=Count('college__location')).distinct().order_by('-dcount')[:1]
    #c=c.values('college__location').annotate(dcount=Count('college__location')).distinct().order_by('-dcount').aggregate(max=Max('dcount'))


    #query to print studentname,collegename,total
    c = MockTest1.objects.all()
    c = c.values('student__name', 'student__college__acronym','total')
    #Student.objects.values('name','mocktest1__total',college__acronym)

    #query to print names of students with total>30
    Student.objects.values('name', 'mocktest1__total', 'college__acronym').filter(mocktest1__total__gt=30).count()

    pass




if __name__=='__main__':
    main()