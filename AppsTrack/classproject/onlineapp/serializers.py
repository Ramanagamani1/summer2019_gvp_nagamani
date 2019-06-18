from django.shortcuts import render
from django.http import HttpResponse
from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework import serializers
from onlineapp.models import College,Student,MockTest1


class CollegeSerializer(serializers.ModelSerializer):

    class Meta:
        model = College
        fields = ('name','location','acronym','contact')


class MockTest1Serializer(serializers.ModelSerializer):
     class Meta:
         model=MockTest1
         fields=('id','problem1','problem2','problem3','problem4','total')

     def update(self,instance,validated_data):
         instance.problem1 = validated_data.get('problem1')
         instance.problem2 = validated_data.get('problem2')
         instance.problem3 = validated_data.get('problem3')
         instance.problem4 = validated_data.get('problem4')
         instance.total = validated_data.get('total')
         return instance

class StudentSerializer(serializers.ModelSerializer):
      class Meta:
          model=Student
          fields=('id','name','dob','email','db_folder','dropped_out','college')

class StudentDetailsSerializer(serializers.ModelSerializer):
    mocktest1 = MockTest1Serializer(many=False, read_only=False)
    class Meta:
        model = Student
        fields = ('name','dob','email','db_folder','dropped_out','mocktest1')

    def create(self, validated_data):
        mocktest1_data = validated_data.pop('mocktest1')
        validated_data['college']=College.objects.get(id=self.context['cpk'])
        student=Student.objects.create(**validated_data)
        MockTest1.objects.create(student=student,**mocktest1_data)
        return student

    def update(self,instance,validated_data):
        mocktest1_data=validated_data.pop('mocktest1')
        mocktest1=MockTest1.objects.get(student_id=self.context['sid'])
        serializer=MockTest1Serializer.update(self,mocktest1,mocktest1_data)
        serializer.save()

        instance.name=validated_data.get('name',instance.name)
        instance.dob=validated_data.get('dob',instance.dob)
        instance.email = validated_data.get('email',instance.email)
        instance.db_folder = validated_data.get('db_folder',instance.db_folder)
        instance.dropped_out= validated_data.get('dropped_out',instance.dropped_out)
        instance.save()
        return instance
        pass
